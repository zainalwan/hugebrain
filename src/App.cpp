#include "../headers/App.h"

int HugeBrain::App::run(int &argc, const char* const argv[])
{
    std::string argv_str;
    for(short i = 0; i < argc; i++)
    {
        argv_str = argv[i];
        if(argv_str == "--help")
        {
            HugeBrain::Help help;
            return help.showMessage();
        }
    }
    
    HugeBrain::Person person;
    person.id = 0;
    HugeBrain::Argument argument;
    std::string temp_id_string;
    for(short i = 0; i < argc; i++)
    {
        argv_str = argv[i];
        if(argv_str.find("--id") != std::string::npos)
        {
            temp_id_string = argument.getValue(argv_str);
            if(temp_id_string.size() > 0)
            {
                person.id = std::stol(argument.getValue(argv_str));
            }
        }
        else if(argv_str.find("--name") != std::string::npos)
        {
            person.name = argument.getValue(argv_str);
        }
        else if(argv_str.find("--phone") != std::string::npos)
        {
            person.phone = argument.getValue(argv_str);
        }
        else if(argv_str.find("--email") != std::string::npos)
        {
            person.email = argument.getValue(argv_str);
        }
    }

    HugeBrain::Database db("people_datas.txt");
    std::vector<HugeBrain::Person> people;
    bool verb_argument_exists = false;
    for(short i = 0; i < argc; i++)
    {
        argv_str = argv[i];
        if(argv_str == "--add")
        {
            verb_argument_exists = true;
            people = db.add(person);
            break;
        }
        else if(argv_str == "--edit")
        {
            verb_argument_exists = true;
            people = db.update(person);
            break;
        }
        else if(argv_str == "--delete")
        {
            verb_argument_exists = true;
            people = db.remove(person);
            break;
        }
        else if(argv_str == "--search")
        {
            verb_argument_exists = true;
            people = db.search(person);
            break;
        }
    }

    if(!verb_argument_exists)
    {
        people = db.getAll();
    }

    HugeBrain::View view;
    return view.render(people);
}