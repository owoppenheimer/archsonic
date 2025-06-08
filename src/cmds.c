#include "../include/archsonic_commands.h"
#include <stdlib.h>

const char* pre_commands[]  = {
   "echo sixty six dicks in my ass" // wha?
};
const char* post_commands[] = {
   "echo suka"
};

void exec_pre_cmds(void) {
   /* Execute the commands from array */
   for (int i = 0; i < sizeof(pre_commands) / sizeof(pre_commands[0]); i++) { 
      system(pre_commands[i]);      
   }
}

void exec_post_cmds(void) {
   /* Execute the commands from array */
   for (int i = 0; i < sizeof(post_commands) / sizeof(post_commands[0]); i++) {
      system(post_commands[i]);
   }
}
