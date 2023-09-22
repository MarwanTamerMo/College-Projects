#pragma once
#include <iostream>

using namespace std;

class PhoneNumber
{
private:

	string m_phone;
	string m_type;

public:

	void SetNumber (string num, string type);
	void Show();
	bool Found(string key) const;
	PhoneNumber(string num, string type);
	PhoneNumber();
};

