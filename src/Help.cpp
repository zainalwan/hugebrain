#include "../headers/Help.h"

int HugeBrain::Help::showMessage()
{
    std::cout << "Huge Brain is a contact software. It used to store some datas about the people\n";
    std::cout << "you know, including their name, phone, and email.\n\n";
    std::cout << "Copyright 2021 by Zain Alwan Wima Irfani.\n\n";
    std::cout << "Usage: hugebrain <arguments>\n\n";
    std::cout << "List of available arguments:\n";
    std::cout << "    --help                  Show this help message.\n";
    std::cout << "    --add                   Add a data.\n";
    std::cout << "    --edit                  Edit a data.\n";
    std::cout << "    --delete                Delete a data.\n";
    std::cout << "    --search                Search a data.\n";
    std::cout << "    --id=<id>               Give the id value when querying data.\n";
    std::cout << "    --name=<name>           Give the name when querying data.\n";
    std::cout << "    --phone=<phone>         Give the phone when querying data.\n";
    std::cout << "    --email=<email>         Give the email when querying data.\n";

    return 0;
}