#pragma once
#include <iostream>
#include "PhoneNumber.h"
#include "Contact.h"

class ContactsBook
{
private:

	int m_size;
	int m_count;
	Contact* m_contacts;

public:

	ContactsBook(int);

	void AddContact();
	void DelContact(int);
	void EditContact(int);
	void ShowAll();
	void FindAll(string key);
	bool Found(string) const;

	~ContactsBook();
};

