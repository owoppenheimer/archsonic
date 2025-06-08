#pragma once

#ifndef ARCHSONIC_COMMANDS
#define ARCHSONIC_COMMANDS

extern const char* pre_commands[];
extern const char* post_commands[];

void exec_pre_cmds(void);
void exec_post_cmds(void);

#endif
