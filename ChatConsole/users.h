#pragma once
#include <string>

class User
{
private:
    int _lenght{};
    std::string* _user_name{};
    std::string* _password{};

public:
    User(int lenght);
    User(std::string user_name, std::string password, int lenght);
    ~User();

    std::string getUser(int i) const;
    std::string getPassword(int i) const;
    void setUser(std::string user_name, int i);
    void setPassword(std::string password, int i);
};
