#pragma once
#include <string>

class Chat
{
private:
	int _lenght{};
	std::string* _sender{};
	std::string* _post{};
	std::string* _mail{};


public:

	Chat() = default;
	Chat(int lenght);
	Chat(std::string sender, std::string post, std::string mail, int lenght);
	Chat(const Chat& a);
	~Chat();

	std::string& operator[](int i);
	Chat& operator=(const Chat& a);
	
	int getLenght() const;
	void erase();
	void reallocate(int newLenght);
	void getMail(std::string post) const;
	void setMail(std::string sender_val, std::string post_val, std::string mail_val);

};