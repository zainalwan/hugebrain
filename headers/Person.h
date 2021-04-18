#ifndef PERSON_H
#define PERSON_H

#include <string>

namespace HugeBrain
{
    struct Person
    {
        unsigned long id;
        std::string name;
        std::string phone;
        std::string email;
    };
}


#endif