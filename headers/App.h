#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include <vector>
#include "Help.h"
#include "Argument.h"
#include "Person.h"
#include "Database.h"
#include "View.h"

namespace HugeBrain
{
    class App
    {
    public:
        int run(int &argc, const char* const argv[]);
    };
}

#endif