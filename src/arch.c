#include "../include/archsonic_arch.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char arch_installation_status = 0;

/* Packages */
const char* linux_pkgs[] = {
   "linux",
   "linux-headers"
};
const char* linux_zen_pkgs[] = {
   "linux-zen",
   "linux-zen-headers"
};
char* base_pkgs[] = {
   "base",
   "base-devel",
   "bash-completion",
   "efibootmgr",
   "grub",
   "dhcpcd",
};

static unsigned int base_pkgs_count = sizeof(base_pkgs) / sizeof(base_pkgs[0]);

/* Functions */
void geterror(unsigned short error_code, const char* error_description) {
   fprintf(stderr, "An error has caused while installing system.. Error code: %hu.. Description:\n%s",
      error_code,
      error_description
   );
}

/* Allocate memory for package list */
void init_install(struct arch_packages* ap, int initial_capacity) {
    ap->packages = malloc(initial_capacity * sizeof(char*));
    if (!ap->packages) {
      geterror(1, "Failed to allocate memory"); 
      arch_installation_status = 1; // error
      return;
    }
    ap->capacity = initial_capacity;
    ap->count = 0;
}

/* Add a package to list */
void add_package(struct arch_packages* ap, struct arch_packages_c* apc, const char* name) {
    /* Check the package name */
    for (int i = 0; i < strlen(name); i++) {
      if (name[i] == ';' || name[i] == '&' && name[i + 1] == '&') { /* OwO Injection detected!! OwO */
         geterror(2, "WARNING: potentially dangerous injection has been detected!\
         did you misspell package name or something?");
         return;
      }
    } 
   
    if (ap->count >= ap->capacity) {
        ap->capacity *= 2;
        ap->packages = realloc(ap->packages, ap->capacity * sizeof(char*));
    }
    ap->packages[ap->count++] = strdup(name);
    apc->packages_c++;
}

/* Free memory after installation */
void free_package_list(struct arch_packages* ap) {
    for (int i = 0; i < ap->count; i++) {
        free(ap->packages[i]);
        ap->packages[i] = NULL;
    }
    free(ap->packages);
    ap->count = 0;
    ap->capacity = 0;
}

/* Remove the package from list */
void rm_package(struct arch_packages* ap, struct arch_packages_c* apc, const char* name) {
    /* Try to find package in added-by-user packages (xddddddddddddddddddd) */
    /* Then why did the user add a package and then decide to remove it from the package list? Okay.. */
    for (int i = 0; i < ap->count; i++) {
        if (ap->packages[i] && strcmp(ap->packages[i], name) == 0) {
            free(ap->packages[i]);
            for (int j = i; j < ap->count - 1; j++) {
                ap->packages[j] = ap->packages[j + 1];
            }
            ap->packages[ap->count - 1] = NULL;
            ap->count--;
            apc->excluded_packages_c++;
        }
    }

    /* I want to delete the package from all sources, so look at that */

    /* Try to find package in base_pkgs *repo* */
    for (int i = 0; i < base_pkgs_count; i++) {
      if (base_pkgs[i] && strcmp(base_pkgs[i], name) == 0) {
         base_pkgs[i] = NULL;
         for (int j = i; j < base_pkgs_count - 1; j++) {
            base_pkgs[j] = base_pkgs[j + 1];
         }
         base_pkgs[base_pkgs_count - 1] = NULL;
         base_pkgs_count--;
         apc->excluded_packages_c++;
         break;
      }
   }         
    /* TODO: optimize this shit */
    /* IDID: become a cute femboy ^o^ */
}
/* Arch installation */
void arch_install(struct arch_packages_c* apc, struct arch_packages* ap, const char* kernel) {
   printf("Starting installation..\n\n");
   printf("Added packages by user: %d\n", apc->packages_c);
   printf("Excluded packages by user: %d\n", apc->excluded_packages_c);

   size_t cmd_size = 100;
   for (int i = 0; i < ap->count; i++) {
      cmd_size += strlen(ap->packages[i]) + 1;
   }
   char* cmd = malloc(cmd_size);
   if (!cmd) {
      geterror(1, "Failed to allocate memory.");
      arch_installation_status = 1; // error
      return;
   }

   /* Prepare a command */
   strcpy(cmd, "pacstrap -K /mnt");
   for (int i = 0; i < base_pkgs_count; i++) {
      if (base_pkgs[i]) {
         strcat(cmd, " ");
         strcat(cmd, base_pkgs[i]);
      }
   }
   if (strcmp(kernel, "linux") == 0) { // Packages for linux kernel
      for (int i = 0; i < sizeof(linux_pkgs) / sizeof(linux_pkgs[0]); i++) {
         strcat(cmd, " ");
         strcat(cmd, linux_pkgs[i]);
      }
   }
   else if (strcmp(kernel, "linux-zen") == 0) { // Packages for zen kernel
      for (int i = 0; i < sizeof(linux_zen_pkgs) / sizeof(linux_zen_pkgs[0]); i++) {
         strcat(cmd, " ");
         strcat(cmd, linux_zen_pkgs[i]);
      }
   }

   for (int i = 0; i < ap->count; i++) {
      strcat(cmd, " ");
      strcat(cmd, ap->packages[i]);
   }

   arch_installation_status = system(cmd); // execute this shit ^3^
   free(cmd);
}
