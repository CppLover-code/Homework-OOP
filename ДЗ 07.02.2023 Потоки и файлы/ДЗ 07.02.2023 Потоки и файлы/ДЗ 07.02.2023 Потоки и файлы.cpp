/* Задача 1: Дан текстовый файл. Необходимо создать новый файл, в который
			 переписать из исходного файла все слова, состоящие не менее чем из семи букв.
   Задача 2: Дан текстовый файл. Необходимо переписать его строки в другой файл. 
             Порядок строк во втором файле должен совпадать с порядком строк в заданном файле.
   Задача 3: Создать и инициализировать массив из 4-х объектов типа Дробь (Fraction)
             и записать этот массив в файл в бинарном режиме.Затем создать другой массив
			 из 4-х объектов типа Дробь и считать в этот массив объекты из этого файла.
   Задача 4: Создать и инициализировать массив из 4-х объектов типа Дробь (Fraction) 
             и записать этот массив в файл в бинарном режиме.Затем создать объект типа Дробь
			 и считать из этого файла в этот объект данные предпоследнего объекта массива.
			 Использовать позиционирование по файлу.
*/
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//  cout << " Ex.1" << endl;
//	ifstream text1("Ex1.txt");										// чтение из файла
//	ofstream new1("Result1.txt");									// запись в файл
//
//	if (!text1)														// проверка открылся ли файл
//	{
//		cerr << " The file Ex1.txt could not be opened for reading!" << endl;
//		exit(1);
//	}
//	if (!new1)
//	{
//		cerr << " The file Result1.txt could not be opened for writing!" << endl;
//		exit(1);
//	}
//
//	while (!text1.eof())											// пока не конец файла
//	{
//		string str1;
//		text1 >> str1;												// считывается текст до пробела в строку
//		
//		if (size(str1) >= 7 && str1[6] != '.' && str1[6] != ',')	// если в строке 7 и более символов, и последний
//		{															// символ не является точкой или запятой
//			if (str1[str1.length() - 1] == '.' ||                   // если последний символ является точкой или запятой
//				str1[str1.length() - 1] == ',')
//			{
//				str1.erase(str1.length() - 1, 1);                   // стираем знак препинания
//			}
//			
//			new1 << str1 << endl;                                   // записываем "чистое" слово в файл
//		}
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main()
//{
//  cout << " Ex.2" << endl;
//	ifstream text2("Ex2.txt");										// чтение из файла
//	ofstream new2("Result2.txt");									// запись в файл
//
//	if (!text2)														// проверка открылся ли файл
//	{
//		cerr << " The file Ex2.txt could not be opened for reading!" << endl;
//		exit(1);
//	}
//	if (!new2)
//	{
//		cerr << " The file Result1.txt could not be opened for writing!" << endl;
//		exit(1);
//	}
//
//	while (!text2.eof())											// пока не конец файла
//	{
//		string str2;
//		getline(text2,str2);										// считывается целая строка в строку
//		new2 << str2 << endl;                                       // построчная запись в файл    	
//	}
//
//	return 0;
//}

#include <iostream>
#include <fstream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;
public:
	Fraction() = default;
	~Fraction(){}
	void SetFraction()
	{
		cout << " Enter the numerator: ";
		cin >> numerator;
		cout << " Enter denominator: ";
		cin >> denominator;
	}
	void Output()
	{
		cout << " Fraction " << numerator 
			<< "/" << denominator << endl;
	}
};
int main()
{
	cout << " Ex.3 - 4" << endl;

	ofstream text3("Ex3.txt", ios::binary);		// запись в бинарном режиме

	const int size = 4;
	Fraction fr1[size]{};						// создаем первый массив объектов Fraction fr1

	for (size_t i = 0; i < size; i++)           // инициализируем массив объектами
	{
		cout << "-" << i + 1 << " fraction-\n";
		fr1[i].SetFraction();
	}
	system("cls");

	cout << " First array of fractions\n\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << " Object " << i + 1 << endl;
		fr1[i].Output();
	}
	cout << endl;

	text3.write((char*)&fr1, sizeof(fr1));		// записали массив объектов в файл
	text3.close();                              // ВАЖНО!!! закрыть файловый поток

	ifstream txt3("Ex3.txt", ios::binary);		// чтение в бинарном режиме

	Fraction fr2[size]{};						// создаем второй массив объектов Fraction fr2

	txt3.read((char*)&fr2, sizeof(fr2));		// считываем данные из файла в новый массив объектов

	cout << " Second array of fractions\n\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << " Object " << i + 1 << endl;
		fr2[i].Output();
	}
	cout << endl;

	Fraction fr3;								// создаем один объект класса Fraction
												// от размера массива отнимаем 2, чтоб 
												// оказаться в начале предпоследнего элемента и умножаем на размер объекта
	int pos = (size - 2) * sizeof(fr1[0]);		// находим позицию, с которой надо считать данные

	txt3.seekg(pos, ios::beg);					// перемещаем файловый указатель от начала файла в позицию предпоследнего элемента
	txt3.read((char*)&fr3, sizeof(fr3));        // считываем данные 

	cout << " One object of type Fraction\n\n";
	fr3.Output();

	//cout << " size of array " << sizeof(fr1) << endl; // 32
	//cout << " size of one element " << sizeof(fr1[0]) << endl; // 8
	//cout << " Find pos " << (size - 2) * sizeof(fr1[0]) << endl; //16

	return 0;
}