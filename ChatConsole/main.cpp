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
	chat.setMail("Chat", "all", "����� ���������� � ���!");
	chat.setMail("Denis", "all", "������ ����, ���� ����� �����.");
	chat.setMail("Julia", "all", "������ ����, � ��� :)");
	chat.setMail("Denis", "Julia", "������ ���, ��� ����?");
	chat.setMail("Julia", "Denis", "������ �������, ����� �� ������� ����, � ���� ��� ������, ��� ���?");

	while (true)
	{

		std::cout << "���� � ���. ��� ���������� ������ ���� �������� (q)\n�������� ���� ���: ";
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
					std::cout << "������� ��� ������: ";
					std::cin >> psw;
					if (psw == usr.getPassword(i)) break;
				}
				break;
			}
			else if (usr.getUser(i) == "")
			{
				std::string psw;
				std::cout << "���������� ������ ������������ � �������: " << login << std::endl;
				std::cout << "���������� ������ : ";
				std::cin >> psw;
				usr.setUser(login, i);
				usr.setPassword(psw, i);
				std::cout << "��������������� ����� ������������.\n\n";
				break;
			}

		}
		std::cout << "������� ����:\n";
		chat.getMail(login);
		std::cout << "����� ������ ���� ���������,��� ������ �������� (q).\n";

		std::string msg;
		std::string post;

		while (true)
		{
			std::cout << "[" << login << "]: ";
			std::cin >> msg;
			if (msg == "q" || msg == "Q") break;
			std::cout << "�������� ��� ���������� (all - ����): ";
			std::cin >> post;
			chat.setMail(login, post, msg);
		}
		std::cout << "Chat => " << login << " : ����������, �� ����� ������.\n";
	}

	
	return 0;
}