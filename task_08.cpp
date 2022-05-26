
//  8.Написать игру "Поле чудес".

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>


typedef std::vector<std::string> vec_s;

void initial_vectors(vec_s& words, vec_s& meanings, const std::string& file1, const std::string& file2)
{
	std::string str;  // строка для хранения строк из файла
	std::ifstream fin1(file1); // открываем фаил для чтения
	std::ifstream fin2(file2); // открываем фаил для чтения

	if (fin1.good() && fin2.good())
	{
		while (!fin1.eof())
		{
			std::getline(fin1, str);
			if (str != "") words.push_back(str);
		}

		fin1.close();

		str = "";

		while (!fin2.eof())
		{
			std::getline(fin2, str);
			if (str != "") meanings.push_back(str);
		}

		fin2.close();
	}

	else std::cout << "\nОшибка, не удалось открыть фаилы !!!" << "\n";
}

int main()
{
	system("chcp 1251 > 0");
	srand(time(0));

	std::string file1, file2; // две строки содержащие имена файлов (со словами и со значениями)
	vec_s words, meanings; // два вектора стрингов (со словами и со значениями)
	
	std::cout << "Введите название файла со словами: ";
	std::getline(std::cin, file1);

	std::cout << "Введите название файла со значениями: ";
	std::getline(std::cin, file2);

	file1 += ".txt";
	file2 += ".txt";

	initial_vectors(words, meanings, file1, file2); // заполняем векторы словами и значениями из файлов	

	int value = rand() % words.size();  // выбираем случайное слово
	
	std::string word = "";
	for (int i = 0; i < words[value].length(); i++) word += "#";

	do
	{
		system("cls");

		if (word == words[value])
		{
			std::cout << "\nПоздравляем Вы угадали слово!!! Вы выиграли!!!\n";
			break;
		}

		std::cout << "Слово состоит из " << words[value].length() << " букв\n";
		std::cout << meanings[value] << "\n\n";
		
		std::cout << word << "\n\n";
		std::string str; // переменная для ввода пользователя
		std::cout << "Введите предпологаемое слово, или букву: ";
		std::getline(std::cin, str);

		if (str == words[value])
		{
			std::cout << "\nПоздравляем Вы угадали слово!!! Вы выиграли!!!\n";
			break;
		}

		bool guessed = false;
		if (str.length() == 1)
		{
			for (int i = 0; i < words[value].length(); i++)
			{
				if (str[0] == words[value][i])
				{
					guessed = true;
					word[i] = words[value][i];
				}
			}
		}
		else
		{
			std::cout << "\nВы не угадали слово!!! Вы проиграли!!!\n";
			break;
		}

		if (guessed) std::cout << "\nПоздравляем!!! Вы угадали букву!!!";
		Sleep(2000);

	} while (true);
}