#include "../include/archsonic_arch.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char arch_installation_status = 0;

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
    }
    free(ap->packages);
    ap->count = 0;
    ap->capacity = 0;
}

/* Remove the package from list */
void rm_package(struct arch_packages* ap, struct arch_packages_c* apc, const char* name) {
   for (int i = 0; i < ap->capacity; i++) {
      if (ap->packages[i] == name) {
         free(ap->packages[i]);
      }
   }
   apc->excluded_packages_c++;
}

/* Arch installation */
void arch_install(struct arch_packages_c* apc, struct arch_packages* ap) {
   printf("Starting installation..");
   printf("Added packages by user: %d", apc->packages_c);
   printf("Excluded packages by user: %d", apc->excluded_packages_c);

   size_t cmd_size = 700;
   for (int i = 0; i < ap->count; i++) {
      cmd_size += strlen(ap->packages[i]) + 1;
   }

   char* cmd = malloc(cmd_size);
   if (!cmd) {
      geterror(1, "Failed to allocate memory.");
      arch_installation_status = 1; // error
      return;
   }
}
