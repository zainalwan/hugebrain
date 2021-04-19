#include "../headers/View.h"

void HugeBrain::View::fillColumn(const std::string &content, const short &size)
{
    if(content == "-")
    {
        for(short i = 0; i < size; i++)
        {
            std::cout << '-';
        }
    }
    else
    {
        std::cout << ' ' << content;
        for(short i = 0; i < size - content.size() - 1; i++)
        {
            std::cout << ' ';
        }
    }
}

void HugeBrain::View::createRow(const std::string &side_separator, const
    std::string &inner_separator, const std::string &first_column_content, const
    std::string &second_column_content, const std::string &third_column_content,
    const std::string &fourth_column_content, const std::string
    &fifth_column_content)
{
    std::cout << side_separator;
    fillColumn(first_column_content, 7);
    std::cout << inner_separator;
    fillColumn(second_column_content, 7);
    std::cout << inner_separator;
    fillColumn(third_column_content, 30);
    std::cout << inner_separator;
    fillColumn(fourth_column_content, 25);
    std::cout << inner_separator;
    fillColumn(fifth_column_content, 30);
    std::cout << side_separator << '\n';
}

int HugeBrain::View::render(const std::vector<HugeBrain::Person> &people)
{
    createRow("+", "+", "-", "-", "-", "-", "-");
    createRow("|", "|", "No", "ID", "Name", "Phone", "Email");
    createRow("+", "+", "-", "-", "-", "-", "-");

    std::stringstream no_string_stream;
    std::stringstream id_string_stream;
    
    if(people.size() > 0)
    {
        for(long i = 0; i < people.size(); i++)
        {
            no_string_stream.clear();
            no_string_stream.str("");
            id_string_stream.clear();
            id_string_stream.str("");

            no_string_stream << (i + 1);
            id_string_stream << people.at(i).id;

            createRow("|", "|", no_string_stream.str(), id_string_stream.str(),
                people.at(i).name, people.at(i).phone, people.at(i).email);
        }
    }
    else
    {
        std::cout << '|';
        fillColumn("Data not found.", 103);
        std::cout << "|\n";
    }

    createRow("+", "+", "-", "-", "-", "-", "-");

    return 0;
}