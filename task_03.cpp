
//   3.Создать своеобразный помощник для начинающих писателей для выбора имён персонажей.
//   Есть три файла, в одном - имена, в другом - фамилии, в третьем – отчества.
//   При помощи Math.random() сгенерировать три числа, и из каждого файла вытащить 
//   строку по случайному номеру.Показать на экран имя, фамилию и отчество нового персонажа.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::string get_string()
{
	std::string file_name;
	std::cout << "введите название файла: ";
	std::getline(std::cin, file_name);
	file_name += ".txt";

	std::ifstream fin(file_name); // открываем фаил для чтения
	std::string str; // переменная для хранения строки
	std::vector<std::string> strings; // массив для хранения строк из файла

	if (fin.good())
	{
		while (!fin.eof())
		{
			std::getline(fin, str);
			if (str != "") strings.push_back(str);
		}
		
		fin.close();

		int n = rand() % strings.size(); // выбираем случайную строку

		return strings[n]; // возвращаем случайную строку
	}

	else {
		std::cout << "\nОшибка, не удалось открыть фаил - " << file_name << "\n";
		return "";
	}
}

int main()
{
	system("chcp 1251 > 0");
	srand(time(0));

	std::string str; // строка для хранения результата

	do {
		int n;
		std::cout << "для выбора строки из нового файла введите - 1\nдля выхода и получения результата введите - 0\n";
		std::cin >> n;
		std::cin.ignore(32767, '\n');

		if (n == 1) str += get_string() + " ";
		else if (n == 0) break;

	} while (true);

	std::cout << "\n" << str << "\n";
}