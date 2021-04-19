#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include "Person.h"

namespace HugeBrain
{
    class Database
    {
    private:
        std::string directoryPathString;
        std::string filePathString;

        std::vector<HugeBrain::Person> readFile();
        void writeFile(const std::vector<HugeBrain::Person> &people);
        bool match(const std::string &large, const std::string &small);

    public:
        Database(const std::string &file_name);
        std::vector<HugeBrain::Person> getAll();
        std::vector<HugeBrain::Person> add(HugeBrain::Person &new_person);
        std::vector<HugeBrain::Person> update(HugeBrain::Person &new_person);
        std::vector<HugeBrain::Person> remove(HugeBrain::Person
            &targeted_person);
        std::vector<HugeBrain::Person> search(HugeBrain::Person &person);
    };
}

#endif