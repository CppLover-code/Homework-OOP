/*
Создайте приложение «Телефонная книга». Необходимо хранить данные об
абоненте (ФИО, домашний телефон, рабочий телефон, мобильный телефон,
дополнительная информация о контакте) внутри соответствующего класса.
Наполните класс переменными-членами, конструкторами, inline-функциями
-членами, реализуйте деструктор. Обязательно необходимо выделять
динамически память под ФИО. Предоставьте пользователю возможность
добавлять новых абонентов, удалять абонентов, искать абонентов по
ФИО, показывать всех абонентов.
*/
#include <iostream>
#include <Windows.h>

class Contact
{
	char* name;
	char* home_tel;
	char* work_tel;
	char* mob_tel;
	char* add_inf;

public:
	Contact()
	{
		std::cout << "Constructor by default\n";
		name = nullptr;
		home_tel = nullptr;
		work_tel = nullptr;
		mob_tel = nullptr;
		add_inf = nullptr;
	}
	Contact(const char* Name, const char* Home_tel, const char* Work_tel, const char* Mob_tel, const char* Add_inf)
	{
		std::cout << "Constructor with parameters\n";

		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);

		home_tel = new char[strlen(Home_tel) + 1];
		strcpy_s(home_tel, strlen(Home_tel) + 1, Home_tel);

		work_tel = new char[strlen(Work_tel) + 1];
		strcpy_s(work_tel, strlen(Work_tel) + 1, Work_tel);

		mob_tel = new char[strlen(Mob_tel) + 1];
		strcpy_s(mob_tel, strlen(Mob_tel) + 1, Mob_tel);

		add_inf = new char[strlen(Add_inf) + 1];
		strcpy_s(add_inf, strlen(Add_inf) + 1, Add_inf);

	}
	void Output()
	{
		if (name == nullptr || home_tel == nullptr || work_tel == nullptr || mob_tel == nullptr || add_inf == nullptr)
		{
			std::cout << "Empty object!\n";
			return;
		}

		std::cout << "\n" << "FIO: " << name << std::endl
			<< "Home phone: " << home_tel << std::endl
			<< "Work phone: " << work_tel << std::endl
			<< "Mobile phone: " << mob_tel << std::endl
			<< "Additional Information: " << add_inf << std::endl;
	}
	bool Search(const char* Search)
	{
		char* srch = new char[strlen(Search) + 1];
		strcpy_s(srch, strlen(Search) + 1, Search);

		if (_stricmp(name, srch) == 0)
		{
			//Output();
			return true;
		}
		else return false;//std::cout << " Contact not found!\n";
	}
	bool Delete(const char* Del)
	{
		char* del = new char[strlen(Del) + 1];
		strcpy_s(del, strlen(Del) + 1, Del);

		if (_stricmp(name, del) == 0)    // если совпадение найдено, то освобождаем поля текущего объекта и возвращаем true 
		{
			delete[] name;
			delete[] home_tel;
			delete[] work_tel;
			delete[] mob_tel;
			delete[] add_inf;

			return true;
		}
		else return false;              // иначе возвращаем false
	}

	/*~Contact()
	{
		std::cout << add_inf << "Destruct\n";
		delete[] name;
		delete[] home_tel;
		delete[] work_tel;
		delete[] mob_tel;
		delete[] add_inf;
	}*/
};

int main()
{
	std::cout << " PhoneBook \n";

	int s = 0;                                                                             // кол-во контактов записанных в тел книге
	int choice;
	bool flag_s = 0;
	bool flag_d = 0;

	Contact* mas  = new Contact[2];                                                        // массив для хранения контактов
	Contact* temp = new Contact[1];                                                        // временное место хранения 1 объекта	

	const size_t BUF_SIZE = 20;
	char* name     = new char[BUF_SIZE];
	char* home_tel = new char[BUF_SIZE];
	char* work_tel = new char[BUF_SIZE];
	char* mob_tel  = new char[BUF_SIZE];
	char* add_inf  = new char[BUF_SIZE];

	char* search   = new char[BUF_SIZE];
	char* del      = new char[BUF_SIZE];

	do
	{
		std::cout << "1. Add phone\n"
			<< "2. Show all phones \n"
			<< "3. Search by name\n"
			<< "4. Delete contact\n"
			<< "0. Exit\n";
		std::cout << "Make a choice: ";
		std::cin >> choice;

		
		if (std::cin.peek() == '\n') std::cin.get();                                        // если от предыдущих итераций остался символ \n, то стираем его

		switch (choice)
		{
		case 1:
			
			s++;																			// увеличиваем индекс массива

			for (int i = s - 1; i < s; i++)
			{
				std::cout << "Enter details for " << i + 1 << " contact\n";

				std::cout << "FIO: ";
				std::cin.getline(name, BUF_SIZE);

				std::cout << "Home phone: ";
				std::cin.getline(home_tel, BUF_SIZE);

				std::cout << "Work phone: ";
				std::cin.getline(work_tel, BUF_SIZE);

				std::cout << "Mobile phone: ";
				std::cin.getline(mob_tel, BUF_SIZE);

				std::cout << "Additional Information: ";
				std::cin.getline(add_inf, BUF_SIZE);

				mas[i] = { name, home_tel, work_tel, mob_tel, add_inf };					// срабатывает конструктор и деструктор (-здесь из-за выхода из области видимости) 
			}
			Sleep(1500);
			system("cls");

			break;

		case 2:
			for (int i = 0; i < s; i++)
			{
				std::cout << "Contact " << i + 1 << "\n";

				mas[i].Output();
				std::cout << "\n";
			}
			//Sleep(1500);
			//system("cls");
			break;

		case 3:

			std::cout << "Enter a name to search: ";
			std::cin.getline(search, BUF_SIZE);

			for (int i = 0; i < s; i++)
			{
				if (mas[i].Search(search) == true)
				{
					mas[i].Output();
					std::cout << "\n";
					flag_s = 1;
				}
			}
			if (flag_s == 0) std::cout << " Contact not found!\n";

			Sleep(2500);
			system("cls");

			break;

		case 4:
			std::cout << "Enter a name to delete: ";
			std::cin.getline(del, BUF_SIZE);

			for (int i = 0; i < s; i++)
			{
				if (mas[i].Delete(del) == true)
				{
					std::cout << "Contact removed! " << i + 1 << " \n";
					for (int k = i; k < s; k++)                                                 // смещаем объекты влево, начиная с позиции удаленного 
					{
						temp[0] = mas[k + 1];
						mas[k]  = temp[0];
						temp[0] = mas[k];
					}
					flag_d = 1;
					s--;                                                                        // уменьшаем массив на 1, чтоб после смещения не осталось последнего элемента
				}
			}
			if (flag_d == 0) std::cout << " Contact not found!\n";

			Sleep(1500);
			system("cls");

			break;

		case 0:

			system("cls");
			exit(0);

			break;

		default:
			std::cout << "Selected the wrong menu item!\n";
		}

	} while (choice != 0);

	delete[] mas;
	delete[] name;
	delete[] home_tel;
	delete[] work_tel;
	delete[] mob_tel;
	delete[] add_inf;

	delete[] search;
	delete[] del;

	return 0;
}

