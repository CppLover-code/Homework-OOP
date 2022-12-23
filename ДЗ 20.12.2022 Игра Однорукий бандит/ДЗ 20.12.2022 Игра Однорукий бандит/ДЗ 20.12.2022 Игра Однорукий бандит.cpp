/*
	Создать имитацию игры «однорукий бандит». Например,
	при нажатии кнопки «Enter» происходит «вращение»
	трех барабанов (естественно, количество шагов вращений
	каждого из них выбирается случайно), на которых
	изображены разные значки; и если выпадает определенная
	комбинация, то игрок получает какой-то выигрыш
	(использовать кольцевую очередь).
*/
#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <fstream>
#include "Reel.h"

using namespace std;

int main()
{
	setlocale(0, "RUS");
	srand(time(0));																// автоматическая рандомизация

	cout << " Игра \"Однорукий бандит\"\n" << "\n";
	cout << " Правила игры\n" << "\n";

	string getcontent1;
	ifstream openfile1("rules.txt");

	if (openfile1.is_open())
	{
		while (getline(openfile1, getcontent1))
		{
			cout << getcontent1 << "\n" << "\n";
		}
		openfile1.close();
	}
	else
	{
		cout << " Файл не найден!\n";
	}

	int n1 = 0, n2 = 0, n3 = 0;													// рандомные числа
	string str; 

	int credit = 7000;															// начальный счёт игрока
	const int removal = 1000;													// снятие за каждый показ комбинации
	int choice;																	// выбор операции

	Reel b1(10);
	for (int i = 0; i < 10; i++) b1.Add(rand() % 8);
	//b1.Show();																//показ очереди

	Reel b2(10);
	for (int i = 0; i < 9; i++) b2.Add(1 + rand() % 7); 
	//b2.Show();

	Reel b3(10);
	for (int i = 0; i < 8; i++) b3.Add(rand() % 8);
	//b3.Show();

	do
	{
		cout << " На вашем счету " << credit << " кредитов\n";
		cout << " Меню операций:\n";
		cout << " Крутить барабан - 1\n";
		cout << " Остановить игру - 0\n";
		cin >> choice;

		b1.reelRandom(n1);														//извлечение элемента, получение рандомного чиcла
		//b1.Show();

		b2.reelRandom(n2);
		//b2.Show();

		b3.reelRandom(n3);
		//b3.Show();

		switch (choice)
		{
		case 1:
			
			str = " " + to_string(n1) + " " 
					  + to_string(n2) + " " 
					  + to_string(n3);											// конвертация int в строку
			MessageBoxA(NULL, str.c_str(), " Комбинация", MB_OK);				// вывод комбинации в окно
			cout << " Комбинация " << n1 << n2 << n3 << "\n\n";
			credit -= removal;

			if (n1 == 0 && n2 == 0 && n3 == 0 ||
				n1 == 1 && n2 == 1 && n3 == 1 ||
				n1 == 2 && n2 == 2 && n3 == 2 ||
				n1 == 3 && n2 == 3 && n3 == 3 ||
				n1 == 4 && n2 == 4 && n3 == 4 ||
				n1 == 5 && n2 == 5 && n3 == 5)
			{
				credit += 3000;
				system("color 20");
				Sleep(500);
				system("color 0F");
				cout << " Призовая комбинация!\n" 
					 << " Вы выйграли 3000 кредитов.\n" << "\n";
			}

			else if (n1 == 5 || n1 == 5 && n2 == 5)								// призовая комбинация
			{
				credit += 2000;
				system("color 20");
				Sleep(500);
				system("color 0F");
				cout << " Призовая комбинация!\n" 
					 << " Вы выйграли 2000 кредитов.\n" << "\n";
			}

			else if (n1 == 6 && n2 == 6 && n3 == 6)								// штрафная комбинация
			{
				credit -= 3000;
				system("color C0");
				Sleep(500);
				system("color 0F");
				cout << " Штрафная комбинация!\n" 
					 << " Вы потеряли 3000 кредитов.\n" << "\n";
			}

			else if (n1 == 7 && n2 == 7 && n3 == 7)								// комбинация джек-пота
			{																	// конец игры (выигрышь)
				credit += 100000;
				system("color 20");
				Sleep(500);
				system("color 10");
				Sleep(500);
				system("color 50");
				Sleep(500);
				system("color 0F");
				cout << " Джек-пот!!!\n" << " Вы выйграли!\n";
				cout << " На вашем счету " << credit << " кредитов.\n";
				MessageBoxA(NULL, " Спасибо за игру. Заберите свой выигрышь в кассе!", " ", MB_OK); 

				break;															
			}
			else if (n1 == 7 || n1 == 7 && n2 == 7)								// призовая комбинация
			{
				credit += 2000;
				system("color 20");
				Sleep(500);
				system("color 0F");
				cout << " Призовая комбинация!\n" 
					 << " Вы выйграли 2000 кредитов.\n" << "\n";
			}
			break;

		case 0:
			credit = 0;
			cout << " Вы завершили игру\n";
			break;

		default:
			cout << " Неправильный ввод!\n\n";
		}

	} while (credit != 0);

	if (credit == 0)
	{
		system("color 40");
		Sleep(500);
		system("color 0F");
		cout << " На вашем счету " << credit << " кредитов\n";
		cout << " Попытайте удачу в другой раз!\n";
	}

	return 0;
}