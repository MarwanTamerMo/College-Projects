#include "PhoneNumber.h"

PhoneNumber::PhoneNumber()
{

}

PhoneNumber::PhoneNumber(string num, string type)
{
	SetNumber(num, type);
}

void PhoneNumber::SetNumber(string num, string type)
{

	m_phone = num;
	m_type = type;

}

void PhoneNumber::Show()
{
	cout << "\tNumber: " << m_phone << endl;
	cout << "\tType: " << m_type << endl;
}

{
	return (m_phone.compare(key) == 0);
}

