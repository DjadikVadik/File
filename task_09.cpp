
//  9.Написать игру "Виселица".

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

void initial_vectors(std::vector<std::string>& str_file, const std::string& file)
{
	std::string str;  // строка для хранения слов
	std::ifstream fin(file); // открываем фаил для чтения


	if (fin.good())
	{
		while (!fin.eof())
		{
			str = "";
			fin >> str;
			if (str != "") str_file.push_back(str); // пишем слово в массив
		}
		fin.close();
	}

	else std::cout << "\nОшибка, не удалось открыть фаилы !!!" << "\n";
}

int main()
{
	system("chcp 1251 > 0");

	std::string file; // строка содержащая имя файла
	std::vector<std::string> str_file; // вектор стрингов содержащий слова из файла

	std::cout << "Введите название файла со словами: ";
	std::getline(std::cin, file);
	file += ".txt";

	initial_vectors(str_file, file);

	int value = rand() % str_file.size();  // выбираем случайное слово

	std::string word = "";
	for (int i = 0; i < str_file[value].length(); i++) word += "#";
	int n = 0; //переменная для проверки количества попыток

	do
	{
		system("cls");

		if (word == str_file[value])
		{
			std::cout << "\nПоздравляем Вы угадали слово!!! Вы выиграли!!!\n";
			break;
		}

		std::cout << "Слово состоит из " << str_file[value].length() << " букв\n";
		std::cout << word << "\n\n";

		char c; // переменная для ввода пользователя
		std::cout << "Введите предпологаемую букву: ";
		std::cin >> c;

		bool guessed = false;  //  проверка....угадал ли пользователь букву

		for (int i = 0; i < str_file[value].length(); i++)
		{
			if (c == str_file[value][i])
			{
				guessed = true;
				word[i] = str_file[value][i];
			}
		}

		if (guessed) std::cout << "\nПоздравляем!!! Вы угадали букву!!!";
		else
		{
			n++;
			if (n == 1) system("1.png"); // открываем ресунок с виселицей...шуткой и дальнейщими инструкциями
			else if (n == 2) system("2.png"); // рисунок с головой в виселице
			else if (n == 3) system("3.png"); // + туловище
			else if (n == 4) system("4.png"); // + рука
			else if (n == 5) system("5.png"); // + рука
			else if (n == 6) system("6.png"); // + нога
			else if (n == 7)
			{
				system("7.png"); // весь человечек  и надпись о том что вы проиграли
				break;
			}
		}
		Sleep(2000);

	} while (true);
}

