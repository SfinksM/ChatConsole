#include <iostream>
#include <string>



using namespace std;

class User {
public:
    User(std::string user_name, std::string password) : _user_name(user_name), _password(password) {}
    ~User() {};


private:
    std::string _user_name;
    std::string _password;
};

void reg_new_user()
{
    string name, pass;
    cout << "Введите ваше имя: ";
    cin >> name;
    cout << "\nПридумайте пароль: ";
    cin >> pass;
    User(name, pass);
    //enter_chat();
}

void user()
{
    cout << "\nВыбирите необходимое действие:\n 1) Регисрация\n 2) Вход\n";
    string option;
    cin >> option;
    int option_id;

    try
    {
        option_id = stoi(option);

    }
    catch (const std::exception& e)
    {
        std::cout << "Выбор 1 или 2, других вариантов нет, сделайте правильный выбор!" << std::endl;
        user();
    }

    switch (option_id) {
    case 1:
        reg_new_user();
        break;
    case 2:
        //enter_chat();
        break;
    default:
        std::cout << "Выбор 1 или 2, других вариантов нет, сделайте правильный выбор!" << std::endl;
        break;
    };
}





int main()
{
    setlocale(LC_ALL, "");

	cout << "Добро пожаловать в чат!\n";
    user();
    //chat();
	

	return 0;
}