#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Person.h"

namespace HugeBrain
{
    class View
    {
    public:
        void fillColumn(const std::string &content, const short &size);
        void createRow(const std::string &side_separator, const std::string
            &inner_separator, const std::string &first_column_content, const
            std::string &second_column_content, const std::string
            &third_column_content, const std::string &fourth_column_content,
            const std::string &fifth_column_content);
        int render(const std::vector<HugeBrain::Person> &people);
    };
}

#endif