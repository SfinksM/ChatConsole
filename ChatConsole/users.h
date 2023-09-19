#pragma once


class User
{
private:
    int _lenght{};
    std::string* _user_name{};
    std::string* _password{};

public:
    User() = default;
    User(std::string user_name, std::string password, int lenght)
    {
        _lenght = lenght;
        _user_name = new std::string[lenght]{};
        _password = new std::string[lenght]{};
    }
    ~User()
    {
        delete[] _user_name;
        delete[] _password;
    }

    std::string getUser(int i) const
    {
        if (i >= 0 && i < _lenght)
        {
            return _user_name[i];
        }
    }

    std::string getPassword(int i) const
    {
        if (i >= 0 && i < _lenght)
        {
            return _password[i];
        }
    }
    void setUser(std::string user_name, int i)
    {
        _user_name[i] = user_name;
    }
    void setPassword(std::string password, int i)
    {
        _password[i] = password;
    }
};
