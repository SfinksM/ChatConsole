#include "chat.h"
#include <iostream>
#include <string>


Chat::Chat(int lenght) : _lenght{ lenght }
{
	_sender = new std::string[lenght]{};
	_post = new std::string[lenght]{};
	_mail = new std::string[lenght]{};
}
Chat::Chat(std::string sender, std::string post, std::string mail, int lenght)
{
	_lenght = lenght;
	_sender = new std::string[lenght]{};
	_post = new std::string[lenght]{};
	_mail = new std::string[lenght]{};
}
Chat::Chat(const Chat& a)
{
	reallocate(a.getLenght());
	for (int i = 0; i < _lenght; ++i)
	{
		_sender[i] = a._sender[i];
		_post[i] = a._post[i];
		_mail[i] = a._mail[i];
	}
}
Chat::~Chat()
{
	delete[] _sender;
	delete[] _post;
	delete[] _mail;
}

std::string& Chat::operator[](int i)
{
	if (i >= 0 && i < _lenght)
	{
		return _sender[i];
		return _post[i];
		return _mail[i];
	}
	else throw "bad_range";
}
Chat& Chat::operator=(const Chat& a)
{
	if (&a == this)
		return *this;
	reallocate(a.getLenght());
	for (int i = 0; i < _lenght; ++i)
	{
		_sender[i] = a._sender[i];
		_post[i] = a._post[i];
		_mail[i] = a._mail[i];

	}
	return *this;
}

int Chat::getLenght() const
{
	return _lenght;
}
void Chat::erase()
{
	delete[] _sender;
	delete[] _post;
	delete[] _mail;
	_sender = nullptr;
	_post = nullptr;
	_mail = nullptr;
	_lenght = 0;
}
void Chat::reallocate(int newLenght)
{
	erase();
	if (newLenght <= 0)
		return;
	_sender = new std::string[newLenght]{};
	_post = new std::string[newLenght]{};
	_mail = new std::string[newLenght]{};
	_lenght = newLenght;
}
void Chat::getMail(std::string post) const
{
	for (int i = 0; i < _lenght; i++)
	{
		if (_post[i] == post || _post[i] == "all")
		{
			std::cout << _sender[i] << " => " << _post[i] << " : " << _mail[i] << std::endl;
		}
	}
}
void Chat::setMail(std::string sender_val, std::string post_val, std::string mail_val)
{
	std::string* sender{ new std::string[_lenght + 1] };
	for (int before = 0; before < _lenght; ++before)
		sender[before] = _sender[before];
	sender[_lenght] = sender_val;
	delete[] _sender;
	_sender = sender;

	std::string* post{ new std::string[_lenght + 1] };
	for (int before = 0; before < _lenght; ++before)
		post[before] = _post[before];
	post[_lenght] = post_val;
	delete[] _post;
	_post = post;

	std::string* mail{ new std::string[_lenght + 1] };
	for (int before = 0; before < _lenght; ++before)
		mail[before] = _mail[before];
	mail[_lenght] = mail_val;
	delete[] _mail;
	_mail = mail;

	++_lenght;
}