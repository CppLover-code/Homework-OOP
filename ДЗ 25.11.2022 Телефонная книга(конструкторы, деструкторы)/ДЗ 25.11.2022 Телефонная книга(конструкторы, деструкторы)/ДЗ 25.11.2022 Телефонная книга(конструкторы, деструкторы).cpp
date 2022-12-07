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
#include "Contact.h"

int main()
{
	system("title PhoneBook");

	int count = 0;																				// кол-во абонентов в книге
	int number = 1;																				// номер абонента в книге
	int choice;

	//Contact contact; contact.Add(mas, count, number); // если функции внутри класса
	Contact* mas  = new Contact[count];                                                         // массив для хранения контактов

	do
	{
		std::cout << "1. Add phone\n"
			<< "2. Show all phones \n"
			<< "3. Search by name\n"
			<< "4. Delete contact\n"
			<< "0. Exit\n";
		std::cout << "Make a choice: ";
		std::cin >> choice;
		std::cout << "\n";
		
		if (std::cin.peek() == '\n') std::cin.get();                                        // если от предыдущих итераций остался символ \n, то стираем его

		switch (choice)
		{
		case 1:
			
			Add(mas, count, number);
			Sleep(1500);
			system("cls");
			break;

		case 2:

			for (int i = 0; i < count; i++)
			{
				mas[i].Output(i + 1);
				std::cout << "\n";
			}
			break;

		case 3:

			Search(mas,count);

			Sleep(2500);
			system("cls");
			break;

		case 4:
			Delete(mas, count, number);
			Sleep(2500);
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

	return 0;
}