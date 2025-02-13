#ifndef __LOGGING__
#define __LOGGING__

#ifndef __TYPES__
    #include <iostream>
    using String = std::string;
#endif

#include <LangHelpers.hpp>


class LogTags
{
    public:
        static const char* DEFAULT_DEBUG_TAG;
        static const char* DEFAULT_ERROR_TAG;
        static const char* DEFAULT_INFO_TAG;
        static const char* DEFAULT_WARNING_TAG;
};


void log_d (const char* message);
void log_d (const char* message, Args<const char*> params);

void log_e (const char* message);
void log_ec (const char* error, const char* cause);

void log_i (const char* message);
void log_i (const char* message, Args<const char*> params);

void log_w (const char* message);
void log_w (const char* message, Args<const char*> params);

#endif
