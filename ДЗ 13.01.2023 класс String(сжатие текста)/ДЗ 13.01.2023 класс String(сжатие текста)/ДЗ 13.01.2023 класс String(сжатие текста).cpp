/*
	В строке текста записаны слова, разделенные пробелами в произвольном количестве.
	Сжатие текста состоит в том, что между словами остается по одному пробелу, а после
	последнего слова пробелы удаляются(пробелы перед первым словом сохраняются).Если
	строка содержит только пробелы, то все они сохраняются.Написать функцию, сжимающую
	описанным образом текст.
*/
#include <iostream>
#include <string>
using namespace std;

class String
{
	string s;
public:
	String()
	{
		//cout << " Constructor by default " << "\n";
		cout << " Enter text (with unlimited spaces):\n";
		getline(cin, s);
	}
	String(string txt)
	{
		//cout << " Constructor with param " << "\n";
		s = txt;
	}
	~String()
	{
		//cout << " Desructor " << "\n";
	}
	void show();
	String compression();
};

void String::show()
{
	cout << s << "\n\n";
}

String String::compression()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))									// находим самую первую букву в строке
		{
			int k = i;
			for (; k < s.length(); k++)						// запускаем цикл с первой буквы до конца строки
			{
				if (isspace(s[k]) && isspace(s[k + 1]))		// если текущий и следующий элемент является пробелом 
				{
					s.erase(k + 1, 1);						// стираем следующий элемент
					k--;
				}
			}
			break;											// прекращаем работу цикла, когда первая буква найдена
		}
	}
	return *this;
}

int main()
{
	String text;
	text.compression();
	text.show();

	String text2  ("   hello     world!  ");
	text2.show();
	text2.compression();
	text2.show();

	return 0;
}