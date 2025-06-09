#include "../include/archsonic_commands.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void exec_cmds(char* cmds[]) {
   /* Execute the commands from array */
   for (int i = 0; cmds[i] != NULL; i++) { 
      system(cmds[i]);      
   }
}

void add_user(const char* username) {
   /* Check for NULL */
   if (!username) {
      fprintf(stderr, "Couldn't find username! (got 'NULL' instead of 'const char*)\n");
      return;
   }

   /* Check username for injection */
   for (int i = 0; i < strlen(username); i++) {
      if (username[i] == ';' || username[i] == '&' && username[i + 1] == '&') {
         fprintf(stderr, "Hmm.. Have you *accidentally* typed injection in your username?\n");
         return;
      }
   }

   /* Add a user */
   char* user_cmd = malloc(strlen("useradd -m ") + strlen(username) + 1);
   strcpy(user_cmd, "useradd -m ");
   strcat(user_cmd, username);

   system(user_cmd);
   free(user_cmd);
   user_cmd = NULL;
}

void config_passwds(const char *passwd, const char *mode, const char* username) {
   /* Check for NULL */
   if (!passwd || !mode) {
      fprintf(stderr, "Couldn't find password or function call mode (got 'NULL' instead of 'const char*')");
      return;
   }

   /* Check a password for injection */
   for (int i = 0; i < strlen(passwd); i++) {
      if (passwd[i] == ';' || passwd[i] == '&' && passwd[i + 1] == '&') {
         fprintf(stderr, "Hmm.. Have you *accidentally* typed injection in your password?\n");
         return;
      }
   }

   if (strcmp(mode, "root") == 0) {
      /* I know that i could open the pipe without this *ptr, buuut, why not? */
      char* root_cmd = malloc(strlen("passwd") + 1);
      strcpy(root_cmd, "passwd");

      FILE* pipe = popen(root_cmd, "w");
         if (!pipe) {
         fprintf(stderr, "PIPE: Broken pipe! (pipe is equal NULL)\n");
         return;
      }
      fprintf(pipe, "%s\n%s\n", passwd, passwd);

      pclose(pipe);
      free(root_cmd);
      root_cmd = NULL;
      pipe = NULL;
   }

   else if (strcmp(mode, "user") == 0) {
      if (!username) {
         fprintf(stderr, "Couldn't find username! (got 'NULL' instead of 'const char*')\n");
         return;
      }

      char* user_cmd = malloc(strlen("passwd ") + strlen(username) + 1);
      strcpy(user_cmd, "passwd ");
      strcat(user_cmd, username);

      FILE* pipe = popen(user_cmd, "w");
      if (!pipe) {
         fprintf(stderr, "PIPE: Broken pipe! (pipe is equal NULL)\n");
         return;
      }
      fprintf(pipe, "%s\n%s\n", passwd, passwd);

      pclose(pipe);
      free(user_cmd);
      user_cmd = NULL;
      pipe = NULL;
   }

   /* Who reads this, please forgive me for my commentaries and error messages */
   else {
      fprintf(stderr, "Unknown function call mode! (hey, this question is not to you, this question is for DEVS!)\n");
   }
   return;
}