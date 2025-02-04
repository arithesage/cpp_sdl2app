#include <Logging.hpp>

#include <iostream>


void log_e (const char* message)
{
    std::cerr << "[ERROR]: " << message << std::endl; 
}


void log_ec (const char* error, const char* cause)
{
    log_e (error);
    std::cerr << "[CAUSE]: " << cause << std::endl;
    std::cerr << std::endl;
}

