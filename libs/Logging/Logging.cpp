#include <Logging.hpp>


const char* LogTags::DEFAULT_DEBUG_TAG = "[DEBUG]";
const char* LogTags::DEFAULT_ERROR_TAG = "[ERROR]";
const char* LogTags::DEFAULT_INFO_TAG = "[INFO]";
const char* LogTags::DEFAULT_WARNING_TAG = "[WARNING]";


void log_d (const char* message)
{
    std::cout << LogTags::DEFAULT_DEBUG_TAG << " " << message << std::endl;
}


void log_d (const char* message, Args<const char*> params)
{
    String _message = String (message);
    List<const char*> _params = ListFromArgs<const char*> (params);

    
}


void log_e (const char* message)
{
    std::cerr << LogTags::DEFAULT_ERROR_TAG << " " << message << std::endl;
}


void log_ec (const char* error, const char* cause)
{
    log_e (error);
    std::cerr << "[CAUSE]: " << cause << std::endl;
    std::cerr << std::endl;
}


void log_i (const char* message)
{
    std::cout << LogTags::DEFAULT_INFO_TAG << " " << message << std::endl;
}


void log_i (const char* message, Args<const char*> params)
{
    
}


void log_w (const char* message)
{
    std::cout << LogTags::DEFAULT_WARNING_TAG << " " << message << std::endl;
}


void log_w (const char* message, Args<const char*> params)
{
    
}

