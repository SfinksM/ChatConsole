#include <iostream>
#include <string>
#include <Windows.h>
#include "users.h"
#include "chat.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251); // ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

	const int lenght = 20;  // ������ ������� �������������
	User usr(lenght); // ����������� ������ User, �������������
	usr.setUser("�����", 0); // ������������ ��� ����� �����
	usr.setPassword("111", 0); // ������ ������������ �����
	usr.setUser("���", 1); // ������������ ���
	usr.setPassword("000", 1); // ������ 000
	Chat chat(0); // ����������� ������ Chat, ������ ����
	chat.setMail("���_���", "����", "����� ���������� � ���!"); // ��������� �� ���� ,����
	chat.setMail("�����", "����", "������ ����, ���� ����� �����."); // ��������� �� ������ ����
	chat.setMail("���", "����", "������ ����, � ��� :)"); // ��������� �� ��� ����
	chat.setMail("�����", "���", "������ ���, ��� ����?"); // ��������� �� ������ ���
	chat.setMail("���", "�����", "������ �������, ����� �� ������� ����, � ���� ��� ������, ��� ���?"); // ��������� �� ��� ������

	while (true) // ���� ����
	{

		cout << "���� � ���. ��� ���������� ������ ���� �������� (q)\n�������� ���� ���: ";
		string login;
		cin >> login; // ������ ����� ���������������
		if (login == "q" || login == "Q") return 0; // ���� ������� "q" �� ���������� ������ ���������

		for (int i = 0; i < lenght; i++) // ���� �������� ���� ��� ������ ������������
		{
			if (usr.getUser(i) == login) // ���� ������������ � ��������� ������ ������, ��
			{
				while (true) // ��������� �������� ������, ��� �������� ������� � ����������� ������, �� ���� ��������� ���
				{
					string psw;
					cout << "������� ��� ������: ";
					cin >> psw; // ������ ������ ��������� ������������
					if (psw == usr.getPassword(i)) break; // ���� ������ ������ �� ����� �� �����
				}
				break;
			}
			else if (usr.getUser(i) == "") // ���� ������������ �� ������, �� ���������� ������
			{
				string psw;
				cout << "���������� ������ ������������ � �������: " << login << std::endl;
				cout << "���������� ������ : ";
				cin >> psw; // ������ ������ ��� ������ ������������
				usr.setUser(login, i); // ���������� ����� ������ ������������
				usr.setPassword(psw, i); // ���������� ������ ������ ������������
				cout << "��������������� ����� ������������.\n\n";
				break;
			}

		}
		cout << "������� ����:\n";
		chat.getMail(login);
		cout << "����� ������ ���� ���������, ��� ������ �������� (q).\n";

		while (true)
		{
			cout << "[" << login << "]: ";
			string msg; 
			cin.ignore();
			getline(cin, msg);
			if (msg == "q" || msg == "Q") break;
			cout << "�������� ��� ���������� (all(����) - � ����� ���): ";
			string post;
			cin >> post;
			chat.setMail(login, post, msg);
		}
		cout << "Chat => " << login << " : ����������, �� ����� ������.\n";
	}

	
	return 0;
}