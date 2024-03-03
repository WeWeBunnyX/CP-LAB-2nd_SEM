#include <iostream>
#include <map>
#include <string>
using namespace std;

class ContactManager {
private:
    map<string, string> contacts;

public:
    void addContact(const string &name, const string &phoneNumber) {
        contacts[name] = phoneNumber;
        cout << "Contact added successfully!\n";
    }

void searchContact(const string &name) {
    if (contacts.count(name) > 0) {
        cout << "\nContact found:\nName: " << name << "\nPhone Number: " << contacts[name] << endl;
    } else {
        cout << "Contact not found!\n";
    }
}

};

int main() {
    ContactManager contactManager;

    int choice;
    do {
        cout << "\n1. Add a contact\n";
        cout << "2. Search for a contact\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, phoneNumber;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone number: ";
                cin >> phoneNumber;
                contactManager.addContact(name, phoneNumber);
                break;
            }
            case 2: {
                string name;
                cout << "Enter a contact name to search: ";
                cin >> name;
                contactManager.searchContact(name);
                break;
            }
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
