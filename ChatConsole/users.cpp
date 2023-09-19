# include "users.h"
#include <iostream>
#include <string>


User::User(int lenght)
{
        _lenght = lenght;
        _user_name = new std::string[lenght]{};
        _password = new std::string[lenght]{};
}
User::User(std::string user_name, std::string password, int lenght)
{
    *_user_name = user_name;
    *_password = password;
    _lenght = lenght;
}

User::~User()
{
    delete[] _user_name;
    delete[] _password;
}

std::string User::getUser(int i) const
{
    if (i >= 0 && i < _lenght)
        {
        return _user_name[i];
        }
}

std::string User::getPassword(int i) const
{
    if (i >= 0 && i < _lenght)
    {
        return _password[i];
    }
}
void User::setUser(std::string user_name, int i)
{
    _user_name[i] = user_name;
}
void User::setPassword(std::string password, int i)
{
    _password[i] = password;
}