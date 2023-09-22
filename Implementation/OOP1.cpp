#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <Windows.h>
#include "PhoneNumber.h"
#include "Contact.h"
#include "ContacsBook.h"

using namespace std;

int main()
{
	char choice;
	int id;
	bool stay = true;

	ContactsBook contacts(100);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	std::cout << setw(45) << " " << "Welcome to the contacts book" << endl;

	SetConsoleTextAttribute(hConsole, 11);

	cout << setw(20) << " " << setw(75) << setfill('-') << "" << endl;
	cout << setfill(' ');
	
	SetConsoleTextAttribute(hConsole, 15);

	while (stay)
	{
		cout << "Please choose what do you want to do from the menu: \n 1 - Add new contact\n 2 - Edit contact\n 3 - Delete contact \n"
			" 4 - Show contacts\n 5 - Quit " << endl;

		cout << " Your choice is: ";
		cin >> choice;

		switch (choice)
		{
		case '1':

			contacts.AddContact();

			cout << left << setw(75) << setfill('-') << "" << endl;

			break;

		case '2':

			cout << " Enter the contact ID you want to edit: ";
			cin >> id;

			contacts.EditContact(id);

			cout << left << setw(75) << setfill('-') << "" << endl;

			break;

		case '3':

			cout << " Enter the contact id you want to delete: ";
			cin >> id;

			contacts.DelContact(id);

			cout << left << setw(75) << setfill('-') << "" << endl;

			break;


		case '4':

			contacts.ShowAll();

			cout << left << setw(75) << setfill('-') << "" << endl;

			break;

		case '5':

			stay = false;
			break;

		}
	}

	SetConsoleTextAttribute(hConsole, 11);

	cout << " Thank you for your time :)";

	SetConsoleTextAttribute(hConsole, 15);


	return 0;
}