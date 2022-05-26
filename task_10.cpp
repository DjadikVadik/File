
//  10. Написать игру "Балда".

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
	srand(time(0));

	std::string file; // строка содержащая имя файла
	std::vector<std::string> str_file; // вектор стрингов содержащий слова из файла

	std::cout << "Введите название файла со словами: ";
	std::getline(std::cin, file);
	file += ".txt";

	initial_vectors(str_file, file);

	int value = rand() % str_file.size();  // выбираем случайное слово
	std::string str = str_file[value]; //записываем его в отдельную строку
	str_file.~vector(); // уничтожаем вектор....он нам больше не нужен

	std::vector<std::string> vec;

	for (int i = 0; i < 5 * str.length(); i++)   // в нашей игре будет 5 строк
		vec.push_back(std::to_string(i));

	for (int i = 2 * str.length(), k = 0; i < (3 * str.length()); i++, k++)   // средняя строка будет нашим словом
	{
		vec[i] = "";
		vec[i] += str[k];
	}

	int curenter = 0; //счетчик ходов

	do {
		system("cls");
		int n = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < str.length(); j++)
			{
				std::cout << vec[n] << "\t";
				n++;
			}
			std::cout << "\n\n";
		}

		if (curenter % 2 == 0) std::cout << "Ход первого игрока!!!\n";
		else std::cout << "Ход второго игрока!!!\n";

		int k;
		char c;

		std::cout << "Введите номер ячейки в которую хотите поместить символ: ";
		std::cin >> k;
		std::cout << "Введите символ который хотите поместить: ";
		std::cin >> c;

		vec[k] = "";
		vec[k] += c;

		curenter++;

	} while (curenter < str.length() * 4);
}

