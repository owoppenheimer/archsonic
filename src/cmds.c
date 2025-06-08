#include "../include/archsonic_commands.h"
#include "../include/archsonic_arch.h"
#include <stdlib.h>

const char* pre_commands  = {
   "genfstab /"
};
const char* post_commands = {
   "echo suka"
};

void exec_pre_cmds(const char* pre_commands) {
   /* Check the pointer */
   if (!pre_commands) {
      geterror(1, "Couldn't find commands!");  
      return;
   }

   /* Execute the commands from array */
   for (int i = 0; i < sizeof(*pre_commands) / sizeof(pre_commands[0]); i++) { 
      system(&pre_commands[i]);      
   }
}

void exec_post_cmds(const char *post_commands) {
   /* Check the pointer */
   if (!post_commands) {
      geterror(1, "Couldn't find commands!");
      return;
   }

   /* Execute the commands from array */
   for (int i = 0; i < sizeof(*post_commands) / sizeof(post_commands[0]); i++) {
      system(&post_commands[i]);
   }
}
