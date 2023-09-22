#pragma warning(disable: 4996)

#include "Contact.h"
#include "PhoneNumber.h"
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

Contact::Contact() {};

Contact::Contact(int size)
{
	m_id = 0;

	m_phones_size = size;

	m_contacts_count = 0;

	m_age = 0;

	m_phones = new PhoneNumber[m_phones_size];

	added = time(0);// get current date


}

void Contact::User()
{
	int n;

	cout << " Please enter the info of the contact:- \n";

	cout << " ID:";
	cin >> m_id;

	for (int i = 0; i < m_contacts_count; ++i)
	{

	}

	cout << " First Name: ";
	cin >> m_fname;

	cout << " Last Name: ";
	cin >> m_lname;

	cout << " Gender (Male/Female): ";
	cin >> m_gender;

	cout << " City: ";
	cin >> m_city;

	cout << " Age: ";
	cin >> m_age;

	cout << " Note: ";
	cin >> m_note;

	cout << " How many phone numbers do you want to add?: ";
	cin >> n;
	
	cin.ignore();

	for (int i = 0; i < n; ++i)
	{
		string num, type;

		cout << " Phone number " << i + 1 << ": ";
		getline(cin, num);

		cout << " Type of phone number " << i + 1 << ": ";
		getline(cin, type);
		
		PhoneNumber* new_phone = new PhoneNumber(num, type);

		m_phones[m_contacts_count++] = *new_phone;

		cout << endl;
	}

	added = time(nullptr);  //get current date

	cout << " time: " << ctime(&added) << endl; //for print

}

void Contact::Show()
{
	cout << setw(50) << "" << setfill('-') << endl;
	cout << " ID: " << m_id << "\n Full Name: " << m_fname << " " << m_lname << endl;
	cout << " Age : " << m_age << endl;
	cout << " City: " << m_city << endl;
	cout << " Gender: " << m_gender << endl;
	cout << " Note: " << m_note << endl;

	if(m_contacts_count > 0)
	{
		for (int i = 0; i < m_contacts_count; ++i)
		{
			cout << " Phone " << i + 1 << ": " << endl;
			m_phones[i].Show();
		}
	}

	cout << " Time this contact was added: " << ctime(&added);
}

int Contact::GetUserId() const
{
	return m_id;
}

bool Contact::Search(string key)
{
	if(m_fname.compare(key) == 0 || m_lname.compare(key) == 0)
	{
		return true;
	}
	if(m_contacts_count > 0)
	{
		for (int i = 0; i < m_contacts_count; ++i)
		{
			if(m_phones[i].Found(key))
			{
				return true;
			}
			else
			{
				return false;
			}
				
		}
	}

	return true;
}

Contact::~Contact()
{
	delete[] m_phones;
}




