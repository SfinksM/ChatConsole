#include <iostream>
#include <string>
#include "users.h"
#include "chat.h"


int main()
{
	setlocale(LC_ALL, "");

	const int lenght = 20;
	User usr(lenght);
	usr.setUser("Denis", 0);
	usr.setPassword("111", 0);
	usr.setUser("Julia", 1);
	usr.setPassword("000", 1);
	Chat chat(0);
	chat.setMail("Chat", "all", "Добро пожаловать в чат!");
	chat.setMail("Denis", "all", "Добрый день, меня зовут Денис.");
	chat.setMail("Julia", "all", "Добрый день, я Юля :)");
	chat.setMail("Denis", "Julia", "Привет Юля, как дела?");
	chat.setMail("Julia", "Denis", "Привет Дениска, давно не сляшала тебя, у меня все хорошо, как сам?");

	while (true)
	{

		std::cout << "Вход в чат. Для завершения работы чата наберите (q)\nНапишите ваше имя: ";
		std::string login;
		std::cin >> login;
		if (login == "q" || login == "Q") return 0;

		for (int i = 0; i < lenght; i++)
		{
			if (usr.getUser(i) == login)
			{
				while (true)
				{
					std::string psw;
					std::cout << "Введите ваш пароль: ";
					std::cin >> psw;
					if (psw == usr.getPassword(i)) break;
				}
				break;
			}
			else if (usr.getUser(i) == "")
			{
				std::string psw;
				std::cout << "Добавление нового пользователя с логином: " << login << std::endl;
				std::cout << "Придумайте пароль : ";
				std::cin >> psw;
				usr.setUser(login, i);
				usr.setPassword(psw, i);
				std::cout << "Зарегистрирован новый пользователь.\n\n";
				break;
			}

		}
		std::cout << "История чата:\n";
		chat.getMail(login);
		std::cout << "Далее пишите ваши сообщения,для выхода наберите (q).\n";

		std::string msg;
		std::string post;

		while (true)
		{
			std::cout << "[" << login << "]: ";
			std::cin >> msg;
			if (msg == "q" || msg == "Q") break;
			std::cout << "Напишите имя получателя (all - всем): ";
			std::cin >> post;
			chat.setMail(login, post, msg);
		}
		std::cout << "Chat => " << login << " : Досвидания, до новых встреч.\n";
	}

	
	return 0;
}