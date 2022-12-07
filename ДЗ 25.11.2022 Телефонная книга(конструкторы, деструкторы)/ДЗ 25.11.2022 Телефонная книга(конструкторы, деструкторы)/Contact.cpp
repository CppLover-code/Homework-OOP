#include "Contact.h"
#include <iostream>
#include <Windows.h>

void Add(Contact*& mas, int& count, int& numb)
{
	Contact* temp = new Contact[count + 1];
	for (int i = 0; i < count; i++)
	{
		temp[i].number = mas[i].number;

		temp[i].name = new char[strlen(mas[i].name) + 1];
		strcpy_s(temp[i].name, strlen(mas[i].name) + 1, mas[i].name);

		temp[i].home_tel = new char[strlen(mas[i].home_tel) + 1];
		strcpy_s(temp[i].home_tel, strlen(mas[i].home_tel) + 1, mas[i].home_tel);

		temp[i].work_tel = new char[strlen(mas[i].work_tel) + 1];
		strcpy_s(temp[i].work_tel, strlen(mas[i].work_tel) + 1, mas[i].work_tel);

		temp[i].mob_tel = new char[strlen(mas[i].mob_tel) + 1];
		strcpy_s(temp[i].mob_tel, strlen(mas[i].mob_tel) + 1, mas[i].mob_tel);

		temp[i].add_inf = new char[strlen(mas[i].add_inf) + 1];
		strcpy_s(temp[i].add_inf, strlen(mas[i].add_inf) + 1, mas[i].add_inf);
	}

	temp[count].number = numb;

	char tmp[20];
	std::cout << "FIO: ";
	std::cin.getline(tmp, 20);
	temp[count].name = new char[strlen(tmp) + 1];
	strcpy_s(temp[count].name, strlen(tmp) + 1, tmp);

	std::cout << "Home phone: ";
	std::cin.getline(tmp, 20);
	temp[count].home_tel = new char[strlen(tmp) + 1];
	strcpy_s(temp[count].home_tel, strlen(tmp) + 1, tmp);

	std::cout << "Work phone: ";
	std::cin.getline(tmp, 20);
	temp[count].work_tel = new char[strlen(tmp) + 1];
	strcpy_s(temp[count].work_tel, strlen(tmp) + 1, tmp);

	std::cout << "Mobile phone: ";
	std::cin.getline(tmp, 20);
	temp[count].mob_tel = new char[strlen(tmp) + 1];
	strcpy_s(temp[count].mob_tel, strlen(tmp) + 1, tmp);

	std::cout << "Additional Information: ";
	std::cin.getline(tmp, 20);
	temp[count].add_inf = new char[strlen(tmp) + 1];
	strcpy_s(temp[count].add_inf, strlen(tmp) + 1, tmp);

	count++;
	numb++;
	delete[] mas;
	mas = temp;
}

void Search(Contact*& mas, int count)
{
	int flag = 0;
	std::cout << "Enter a name to search: ";
	char Search[20];
	std::cin.getline(Search, 20);

	for (int i = 0; i < count; i++)
	{
		if (_stricmp(mas[i].name, Search) == 0)
		{
			mas[i].Output(i + 1);
			std::cout << "\n";
			flag = 1;
		}
	}
	if (flag == 0) std::cout << " Contact not found!\n";
}
void Delete(Contact*& mas, int& count, int& numb)
{
	short del_numb;
	bool flag = 0;
	std::cout << "Enter a number to delete: ";
	std::cin >> del_numb;

	for (int i = 0; i < count; i++)
	{
		if (mas[i].number == del_numb)
		{
			std::cout << " Contact to delete: " << mas[i].name << std::endl;
			count--;
			numb--;
			flag++;
		}
	}
	short ind = 0;
	Contact* temp = new Contact[count];

	for (size_t i = 0; i < count; i++)
	{
		if (mas[ind].number == del_numb)
		{
			ind++;
			i--;
		}
		else if (mas[ind].number != del_numb)
		{
			temp[i].number = mas[ind].number;

			temp[i].name = new char[strlen(mas[ind].name) + 1];
			strcpy_s(temp[i].name, strlen(mas[ind].name) + 1, mas[ind].name);

			temp[i].home_tel = new char[strlen(mas[ind].home_tel) + 1];
			strcpy_s(temp[i].home_tel, strlen(mas[ind].home_tel) + 1, mas[ind].home_tel);

			temp[i].work_tel = new char[strlen(mas[ind].work_tel) + 1];
			strcpy_s(temp[i].work_tel, strlen(mas[ind].work_tel) + 1, mas[ind].work_tel);

			temp[i].mob_tel = new char[strlen(mas[ind].mob_tel) + 1];
			strcpy_s(temp[i].mob_tel, strlen(mas[ind].mob_tel) + 1, mas[ind].mob_tel);

			temp[i].add_inf = new char[strlen(mas[ind].add_inf) + 1];
			strcpy_s(temp[i].add_inf, strlen(mas[ind].add_inf) + 1, mas[ind].add_inf);
			ind++;
		}
	}
	delete[] mas;
	mas = temp;
	if (flag) std::cout << "Contact removed!\n";
	else
	{
		std::cout << "Contact not found!\n";
		return;
	}
}