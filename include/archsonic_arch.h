#pragma once

#ifndef ARCHSONIC_ARCH
#define ARCHSONIC_ARCH

typedef struct arch_packages_c {

   int packages_c;
   int excluded_packages_c;

} arch_packages_c;

typedef struct arch_packages {

   char** packages;
   int capacity;
   int count;

};

void geterror(unsigned short error_code, const char* error_description);

void init_install(struct arch_packages* ap, int init_capacity);

void add_package(struct arch_packages* ap, struct arch_packages_c* apc, const char* name);

void free_package_list(struct arch_packages* ap);

void rm_package(struct arch_packages* ap, struct arch_packages_c* apc, const char* name);

extern unsigned char arch_installation_status;

void arch_install(struct arch_packages_c* apc, struct arch_packages* packages, const char* kernel);

#endif
