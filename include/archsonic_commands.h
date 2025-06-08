#pragma once

#ifndef ARCHSONIC_COMMANDS
#define ARCHSONIC_COMMANDS

extern const char* pre_commands;
extern const char* post_commands;

void exec_pre_cmds(const char* pre_commands);
void exec_post_cmds(const char* post_commands);

#endif
