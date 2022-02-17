#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Person
{
    string name;
    string email;
    string phone;
    string birthday;

public:
    Person(string _name, string _email, string _phone, string _birthday)
    {
        this->name = _name;
        this->email = _email;
        this->phone = _phone;
        this->birthday = _birthday;
    }
};

class Agenda
{
public:
    vector<Person> contacts;

    void load_contacts(string filename)
    {
        ifstream input(filename);

        string line;
        while(getline(input, line))
        {
            vector<string> words;
            words.clear();
            string tmp = "";
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == ',')
                {
                    words.push_back(tmp);
                    tmp = "";
                } 
                else
                {
                    tmp += line[i];
                }
            }

            if (tmp.size() > 0)
            {
                words.push_back(tmp);
            }

            for (int i = 0; i < words.size(); i++)
            {
                cout << words[i] << endl;
            }

            contacts.push_back(Person(words[0], words[1], words[2], words[3]));
        }
    }
};

int main()
{
    Agenda agenda;
    agenda.load_contacts("contacts.csv");

    return 0;
}
