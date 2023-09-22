#pragma once
#include <iostream>
#include <ctime>
#include "PhoneNumber.h"
using namespace std;


class Contact
{
private:

	int m_id;
	int m_age;
	string m_fname;
	string m_lname;
	string m_city;
	string m_note;
	string m_gender;
	time_t added;

	PhoneNumber* m_phones;

	int m_phones_size;
	int m_contacts_count;

public:

	void User();
	bool Search(string);
	void Show();
	int GetUserId() const;
	Contact(int size);
	Contact();
	~Contact();

};

