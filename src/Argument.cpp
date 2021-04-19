#include "../headers/Argument.h"

std::string HugeBrain::Argument::getValue(std::string argv)
{
    argv = argv.substr(argv.find('=') + 1);
    return argv;
}