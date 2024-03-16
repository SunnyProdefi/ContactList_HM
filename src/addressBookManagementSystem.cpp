#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

struct Contact {
  string name;
  int m_Sex;
  int m_Age;
  string m_Phone;
  string m_Addr;
};

struct AddressBook {
  struct Contact contacts[MAX];
  int m_Size;
};

void showMenu();

void addContact(struct AddressBook *abs);

void showContact(struct AddressBook *abs);

int isExist(struct AddressBook *abs, string name) {
  for (int i = 0; i < abs->m_Size; i++) {
    if (abs->contacts[i].name == name) {
      return i;
    }
  }
  return -1;
}

void deleteContact(struct AddressBook *abs) {
  cout << "Please enter the name you want to delete: " << endl;
  string name;
  cin >> name;
  int ret = isExist(abs, name);
  if (ret != -1) {
    for (int i = ret; i < abs->m_Size; i++) {
      abs->contacts[i] = abs->contacts[i + 1];
    }
    abs->m_Size--;
    cout << "Delete contact successfully" << endl;
  } else {
    cout << "Cannot find the contact" << endl;
  }
  system("pause");
  system("cls");
}

void findContact(struct AddressBook *abs) {
  cout << "Please enter the name you want to find: " << endl;
  string name;
  cin >> name;
  int ret = isExist(abs, name);
  if (ret != -1) {
    cout << "Name:    " << abs->contacts[ret].name << "\t";
    cout << "Sex:     " << (abs->contacts[ret].m_Sex == 1 ? "man" : "woman")
         << "\t";
    cout << "Age:     " << abs->contacts[ret].m_Age << "\t";
    cout << "Phone:   " << abs->contacts[ret].m_Phone << "\t";
    cout << "Address: " << abs->contacts[ret].m_Addr << endl;
  } else {
    cout << "Cannot find the contact" << endl;
  }
  system("pause");
  system("cls");
}

void modifyContact(struct AddressBook *abs) {
  cout << "Please enter the name you want to modify: " << endl;
  string name;
  cin >> name;
  int ret = isExist(abs, name);
  if (ret != -1) {
    string name;
    cout << "Please enter the name: " << endl;
    cin >> name;
    abs->contacts[ret].name = name;
    int sex;
    cout << "Please enter the sex: " << endl;
    cout << "0---woman" << endl;
    cout << "1---man" << endl;
    while (true) {
      cin >> sex;
      if (sex == 0 || sex == 1) {
        abs->contacts[ret].m_Sex = sex;
        break;
      }
      cout << "Please enter the sex: " << endl;
    }
    int age;
    cout << "Please enter the age: " << endl;
    cin >> age;
    abs->contacts[ret].m_Age = age;
    string phone;
    cout << "Please enter the phone: " << endl;
    cin >> phone;
    abs->contacts[ret].m_Phone = phone;
    string addr;
    cout << "Please enter the address: " << endl;
    cin >> addr;
    abs->contacts[ret].m_Addr = addr;
    cout << "Add contact successfully" << endl;
  } else {
    cout << "Cannot find the contact" << endl;
  }
  system("pause");
  system("cls");
}

void clearContact(struct AddressBook *abs) {
  abs->m_Size = 0;
  cout << "Clear all contacts successfully" << endl;
  system("pause");
  system("cls");
}

int main() {
  struct AddressBook abs;
  abs.m_Size = 0;
  int select = 0;
  while (true) {
    showMenu();
    cin >> select;
    switch (select) {
    case 1:
      cout << "Add Contact" << endl;
      addContact(&abs);
      break;
    case 2:
      cout << "Show Contact" << endl;
      showContact(&abs);
      break;
    case 3:
      cout << "Delete Contact" << endl;
      deleteContact(&abs);
      break;
    case 4:
      cout << "Find Contact" << endl;
      findContact(&abs);
      break;
    case 5:
      cout << "Modify Contact" << endl;
      modifyContact(&abs);
      break;
    case 6:
      cout << "Clear All" << endl;
      clearContact(&abs);
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

void showMenu() {
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

void addContact(struct AddressBook *abs) {
  if (abs->m_Size == MAX) {
    cout << "Address Book is full, cannot add new contact" << endl;
    return;
  } else {
    string name;
    cout << "Please enter the name: " << endl;
    cin >> name;
    abs->contacts[abs->m_Size].name = name;
    int sex;
    cout << "Please enter the sex: " << endl;
    cout << "0---woman" << endl;
    cout << "1---man" << endl;
    while (true) {
      cin >> sex;
      if (sex == 0 || sex == 1) {
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
    abs->contacts[abs->m_Size].m_Addr = addr;
    abs->m_Size++;
    cout << "Add contact successfully" << endl;
    system("pause");
    system("cls");
  }
}
void showContact(struct AddressBook *abs) {
  if (abs->m_Size == 0) {
    cout << "Address Book is empty" << endl;
  } else {
    for (int i = 0; i < abs->m_Size; i++) {
      cout << "Name:    " << abs->contacts[i].name << "\t";
      cout << "Sex:     " << (abs->contacts[i].m_Sex == 1 ? "man" : "woman")
           << "\t";
      cout << "Age:     " << abs->contacts[i].m_Age << "\t";
      cout << "Phone:   " << abs->contacts[i].m_Phone << "\t";
      cout << "Address: " << abs->contacts[i].m_Addr << endl;
    }
  }
  system("pause");
  system("cls");
}