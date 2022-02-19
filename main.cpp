#include <iostream>
#include "agenda.h"

using namespace std;

int main()
{
    Agenda agenda;

    agenda.load("contacts.csv");

    int operation = -1;
    string contact, name, email, phone, birthday;

    while (operation != 6)
    {
        cout << "Contact Book" << endl;
        cout << "What would you like to do?" << endl;

        cout << "1 - List Contacts" << endl;
        cout << "2 - Detail Contacts" << endl;
        cout << "3 - Add Contacts" << endl;
        cout << "4 - Remove Contacts" << endl;
        cout << "5 - Save" << endl;
        cout << "6 - Quit" << endl;

        cin >> operation;

        switch (operation)
        {
        case 1:
            agenda.sort_contacts();
            agenda.print();
            break;
        case 2:
            cout << "Enter the name of the contact you want to detail." << endl;
            cin >> contact;
            agenda.detail(contact);
            break;
        case 3:
            cout << "Enter the information in the following order: name, email, phone, date of birth." << endl;
            cin >> name >> email >> phone >> birthday;
            agenda.contacts.push_back(Person(name, email, phone, birthday));
            break;
        case 4:
            cout << "Enter the name of the contact you want to remove." << endl;
            cin >> contact;
            agenda.remove(contact);
            break;
        case 5:
            agenda.save();
            cout << "Saved Changes" << endl;
            break;
        case 6:
            break;
        default:
            break;
        }
    }

    return 0;
}
