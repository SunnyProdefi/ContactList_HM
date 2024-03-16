#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

struct Contact{
    string name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct AddressBook{
    struct Contact contacts[MAX];
    int m_Size;
};

void showMenu();

void addContact(struct AddressBook *abs);

int main(){
    struct AddressBook abs;
    abs.m_Size = 0;
    int select = 0;
    while(true){
        showMenu();
        cin >> select;
        switch(select){
            case 1:
                cout << "Add Contact" << endl;
                addContact(&abs);
                break;
            case 2:
                cout << "Show Contact" << endl;
                break;
            case 3:
                cout << "Delete Contact" << endl;
                break;
            case 4:
                cout << "Find Contact" << endl;
                break;
            case 5:
                cout << "Modify Contact" << endl;
                break;
            case 6:
                cout << "Clear All" << endl;
                break;
            case 0:
                cout << "Exit" << endl;
                system("pause");
                return 0;
                break;
            default:
                break;
        }
    }
    system("pause");
    return 0;
}

void showMenu(){
    cout << "***** Address Book Management System *****" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Show Contact" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. Find Contact" << endl;
    cout << "5. Modify Contact" << endl;
    cout << "6. Clear All" << endl;
    cout << "0. Exit" << endl;
    cout << "Please select the operation: " << endl;
}

void addContact(struct AddressBook *abs){
    if(abs->m_Size == MAX){
        cout << "Address Book is full, cannot add new contact" << endl;
        return;
    }else{
        string name;
        cout << "Please enter the name: " << endl;
        cin >> name;
        abs->contacts[abs->m_Size].name = name;
        int sex;
        cout << "Please enter the sex: " << endl;
        cout << "0---Å®" << endl;
        cout << "1---ÄÐ" << endl;
        while(true){
            cin >> sex;
            if(sex == 0 || sex == 1){
                abs->contacts[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "Please enter the sex: " << endl;
        }
        int age;
        cout << "Please enter the age: " << endl;
        cin >> age;
        abs->contacts[abs->m_Size].m_Age = age;
        string phone;
        cout << "Please enter the phone: " << endl;
        cin >> phone;
        abs->contacts[abs->m_Size].m_Phone = phone;
        string addr;
        cout << "Please enter the address: " << endl;
        cin >> addr;
        abs->contacts[abs->m_Size].m_Addr = addr;}
}