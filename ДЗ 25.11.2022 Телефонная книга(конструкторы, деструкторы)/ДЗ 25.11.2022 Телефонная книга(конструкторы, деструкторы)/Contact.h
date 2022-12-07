#include <iostream>
#include <Windows.h>
//#include "colors.h"

class Contact
{
	

public:
	char* name;
	char* home_tel;
	char* work_tel;
	char* mob_tel;
	char* add_inf;
	int number;
	Contact()
	{
		//std::cout << "Constructor by default\n";
		name = nullptr;
		home_tel = nullptr;
		work_tel = nullptr;
		mob_tel = nullptr;
		add_inf = nullptr;
		number = 0;
	}
	void Set(const char* Name, const char* Home_tel, const char* Work_tel, const char* Mob_tel, const char* Add_inf)
	{
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


	void Output(int n)
	{
		if (name == nullptr || home_tel == nullptr || work_tel == nullptr || mob_tel == nullptr || add_inf == nullptr)
		{
			std::cout << "Empty object!\n";
			return;
		}

		std::cout << "Contact " << n;

		std::cout << "\n" << "FIO: " << name << std::endl
			<< "Home phone: " << home_tel << std::endl
			<< "Work phone: " << work_tel << std::endl
			<< "Mobile phone: " << mob_tel << std::endl
			<< "Additional Information: " << add_inf << std::endl;
	}

	

	~Contact()
	{
		//std::cout << name << "Destruct\n";
		delete[] name;
		delete[] home_tel;
		delete[] work_tel;
		delete[] mob_tel;
		delete[] add_inf;
	}
};

void Add(Contact*& mas, int& count, int& numb);
void Search(Contact*& mas, int count);
void Delete(Contact*& mas, int& count, int& numb);