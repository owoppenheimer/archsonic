#include "../include/archsonic_commands.h"

int main(void) {
   exec_pre_cmds(pre_commands);
   exec_post_cmds(post_commands);

   return 0;
}
