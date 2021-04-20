#include "../headers/Argument.h"

std::string HugeBrain::Argument::getValue(std::string argv)
{
    if(argv.find('=') != std::string::npos)
    {
        return argv.substr(argv.find('=') + 1);
    }
    return "";
}