#pragma once

#ifndef ARCHSONIC_COMMANDS
#define ARCHSONIC_COMMANDS

void exec_cmds(char* cmds[]);

void add_user(const char* username);
void config_passwds(const char* passwd, const char* mode, const char* username);

#endif
