#ifndef __LOGGING__
#define __LOGGING__

#include <iostream>

#include <LangHelpers.hpp>

void log_d (const char* message);
void log_d (const_char* message, Args<const char*> params);

void log_i (const char* message);
void log_i (const char* message, Args<const char*> params);

void log_e (const char* message);
void log_ec (const char* error, const char* cause);

void log_w (const char* message);
void log_w (const char* message, Args<const char*> params);

#endif
