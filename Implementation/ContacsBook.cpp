#include "ContacsBook.h"
#include "PhoneNumber.h"
#include "Contact.h"
#include <iostream>
#include <Windows.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

ContactsBook::ContactsBook(int size)
{
	m_size = size;
	m_contacts = new Contact[size];
	m_count = 0;
}

ContactsBook::~ContactsBook()
{
	delete [] m_contacts;
}

void ContactsBook::AddContact()
{
	Contact* new_contact = new Contact();

	new_contact->User();

	m_contacts[m_count++] = *new_contact;

}

void ContactsBook::ShowAll()
{
	if(m_count == 0)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, 11);


		cout << " No Contacts Found :( " << endl;

		SetConsoleTextAttribute(hConsole, 15);

	}
	else
	{
		for (int i = 0; i < m_count; ++i)
		{
			m_contacts[i].Show();
			cout << endl;
		}
	}
}

void ContactsBook::FindAll(string key)
{
	int found_counter = 0;

	for (int i  = 0; i < m_count; ++i)
	{
		if(m_contacts[i].Search(key))
		{
			m_contacts[i].Show();
		}

		found_counter++;
	}
}

void ContactsBook::DelContact(int id)
{
	if (m_count == 0)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 11);

		cout << " No contact is found to delete :(" << endl;

		SetConsoleTextAttribute(hConsole, 15);


		return;
	}

	bool deleted = false;

	for (int i = 0; i < m_count; ++i)
	{
		if (m_contacts[i].GetUserId() == id)
		{
			if(i == m_count - 1)
			{
				m_count--;
			}
			else
			{
				m_contacts[i] = m_contacts[m_count - 1];
				m_count--;
			}
			deleted = true;
			break;
		}
	}
	if (deleted)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 11);

		cout << " User deleted :)" << endl;

		SetConsoleTextAttribute(hConsole, 15);

	}
	else
	{

		SetConsoleTextAttribute(hConsole, 11);

		cout << " No contact deleted :(" << endl;

		SetConsoleTextAttribute(hConsole, 15);

	}
}

void ContactsBook::EditContact(int id)
{

	if (m_count == 0)
	{

		SetConsoleTextAttribute(hConsole, 11);

		cout << " No contact is found to delete :(" << endl;

		SetConsoleTextAttribute(hConsole, 15);

		return;
	}

	bool edited = false;

	for (int i = 0; i < m_count; ++i)
	{
		if (m_contacts[i].GetUserId() == id)
		{
			m_contacts[i].User();

			edited = true;

			SetConsoleTextAttribute(hConsole, 11);

			cout << " Contact that had ID " << "- " << id << " -" << " was edited successfully :)" << endl;

			SetConsoleTextAttribute(hConsole, 15);

			break;
		}
		
	}
}


