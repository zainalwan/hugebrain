#include "../headers/Database.h"

HugeBrain::Database::Database(const std::string &file_name)
{
    directoryPathString.append(getenv("HOME"));
    directoryPathString.append("/.hugebrain");
    filePathString.append(directoryPathString);
    filePathString.append("/");
    filePathString.append(file_name);

    boost::filesystem::path directory_path(directoryPathString);
    boost::filesystem::path file_path(filePathString);

    if(!boost::filesystem::exists(directory_path))
    {
        boost::filesystem::create_directory(directory_path);
        boost::filesystem::ofstream people_datas_file(file_path, std::ios::out |
            std::ios::binary);
        people_datas_file.close();
    }
    else if(boost::filesystem::exists(directory_path)
        && boost::filesystem::is_directory(directory_path)
        && !boost::filesystem::exists(file_path))
    {
        boost::filesystem::ofstream people_datas_file(file_path, std::ios::out
            | std::ios::binary);
        people_datas_file.close();
    }
}

std::vector<HugeBrain::Person> HugeBrain::Database::getAll()
{
    return readFile();
}

std::vector<HugeBrain::Person> HugeBrain::Database::readFile()
{
    boost::filesystem::path file_path(filePathString);
    boost::filesystem::ifstream people_datas_file(file_path);

    std::string temp_string;
    HugeBrain::Person person;
    std::vector<HugeBrain::Person> people;
    while(std::getline(people_datas_file, temp_string))
    {
        person.id = std::stol(temp_string.substr(0, temp_string.find(',')));
        temp_string = temp_string.substr(temp_string.find(',') + 2);
        person.name = temp_string.substr(0, temp_string.find(','));
        temp_string = temp_string.substr(temp_string.find(',') + 2);
        person.phone = temp_string.substr(0, temp_string.find(','));
        temp_string = temp_string.substr(temp_string.find(',') + 2);
        person.email = temp_string.substr(0, temp_string.find(','));
        temp_string = temp_string.substr(temp_string.find(',') + 2);
        people.push_back(person);
    }
    people_datas_file.close();

    return people;
}

void HugeBrain::Database::writeFile(const std::vector<HugeBrain::Person>
    &people)
{
    boost::filesystem::path file_path(filePathString);
    boost::filesystem::ofstream people_datas_file(file_path);
    for(long i = 0; i < people.size(); i++)
    {
        people_datas_file << people.at(i).id << ", ";
        people_datas_file << people.at(i).name << ", ";
        people_datas_file << people.at(i).phone << ", ";
        people_datas_file << people.at(i).email;
        if(i < people.size() - 1)
        {
            people_datas_file << '\n';
        }
    }
    people_datas_file.close();
}

std::vector<HugeBrain::Person> HugeBrain::Database::add(HugeBrain::Person
    &new_person)
{
    std::vector<HugeBrain::Person> people = readFile();

    if(people.size() == 0)
    {
        new_person.id = 1;
    }
    else
    {
        new_person.id = people.back().id + 1;
    }
    people.push_back(new_person);
    writeFile(people);

    std::cout << new_person.name << "'s datas was successfully saved.\n\n";

    return people;
}

std::vector<HugeBrain::Person> HugeBrain::Database::update(HugeBrain::Person
    &new_person)
{
    if(new_person.id == 0)
    {
        std::cout << "Please give an ID.\n";
        exit(EXIT_FAILURE);
    }

    bool person_is_found = false;
    std::vector<HugeBrain::Person> people = readFile();
    for(std::vector<HugeBrain::Person>::iterator person = people.begin(); person
        < people.end(); person++)
    {
        if((*person).id == new_person.id)
        {
            if(new_person.name.size() > 0)
            {
                (*person).name = new_person.name;
            }
            else
            {
                new_person.name = (*person).name;
            }

            if(new_person.phone.size() > 0)
            {
                (*person).phone = new_person.phone;
            }
            if(new_person.email.size() > 0)
            {
                (*person).email = new_person.email;
            }
            person_is_found = true;
            break;
        }
    }
    writeFile(people);

    if(person_is_found)
    {
        std::cout << new_person.name << "'s datas was successfully updated.\n\n";
    }
    else
    {
        std::cout << "The person doesn't exists.\n\n";
    }

    return people;
}

std::vector<HugeBrain::Person> HugeBrain::Database::remove(HugeBrain::Person
    &targeted_person)
{
    if(targeted_person.id == 0)
    {
        std::cout << "Please give an id.\n";
        exit(EXIT_FAILURE);
    }

    bool person_is_found = false;
    std::vector<HugeBrain::Person> people = readFile();
    for(std::vector<HugeBrain::Person>::iterator person = people.begin(); person
        < people.end(); person++)
    {
        if((*person).id == targeted_person.id)
        {
            targeted_person.name = (*person).name;
            people.erase(person);
            person_is_found = true;
            break;
        }
    }
    writeFile(people);

    if(person_is_found)
    {
        std::cout << targeted_person.name << "'s datas was successfully deleted.\n\n";
    }
    else
    {
        std::cout << "The person doesn't exists.\n\n";
    }

    return people;
}

std::vector<HugeBrain::Person> HugeBrain::Database::search(HugeBrain::Person
    &targeted_person)
{
    std::vector<HugeBrain::Person> people = readFile();
    for(std::vector<HugeBrain::Person>::iterator person = people.begin();
        person < people.end(); person++)
    {
        if((*person).id != targeted_person.id
            && !match((*person).name, targeted_person.name)
            && !match((*person).phone, targeted_person.phone)
            && !match((*person).email, targeted_person.email))
        {
            people.erase(person);
            person--;
        }
    }

    return people;
}

bool HugeBrain::Database::match(const std::string &large, const std::string
    &small)
{
    if((large.size() < 1 || small.size() < 1)
        || boost::to_lower_copy(large).find(boost::to_lower_copy(small)) ==
        std::string::npos)
    {
        return false;
    }
    return true;
}