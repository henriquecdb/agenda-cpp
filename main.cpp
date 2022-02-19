#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Person
{
public:
    string name;
    string email;
    string phone;
    string birthday;

    Person(string _name, string _email, string _phone, string _birthday)
    {
        this->name = _name;
        this->email = _email;
        this->phone = _phone;
        this->birthday = _birthday;
    }

    bool operator<(Person B)
    {
        return this->name < B.name;
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
        while (getline(input, line))
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

            contacts.push_back(Person(words[0], words[1], words[2], words[3]));
        }
    }

    void sort_contacts()
    {
        sort(contacts.begin(), contacts.end());
    }

    void print_contacts()
    {
        cout << "----------------------------------" << endl;
        cout << "Name"
             << "\t\t"
             << "Email"
             << "\t\t\t"
             << "Phone"
             << "\t\t\t"
             << "Birthday" << endl;
        for (int i = 0; i < contacts.size(); i++)
        {
            cout << contacts[i].name << "\t" 
                 << contacts[i].email << "\t" 
                 << contacts[i].phone << "\t\t" 
                 << contacts[i].birthday << endl;
        }
    }
};

int main()
{
    Agenda agenda;
    agenda.load_contacts("contacts.csv");
    agenda.sort_contacts();
    agenda.print_contacts();

    return 0;
}
