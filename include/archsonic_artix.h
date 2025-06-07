#pragma once

#ifndef ARCHSONIC_ARTIX
#define ARCHSONIC_ARTIX

typedef struct artix_packages_c {

   int packages_c;
   int excluded_packages_c;

} artix_packages_c;

static unsigned char artix_installation_status;

void artix_install(int packages_c, int excluded_packages_c, struct artix_packages* packages);

#endif

