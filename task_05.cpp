
//  5.В файле в столбик хранятся русские существительные.Пользователь 
//  вводит слово.Задача программы подобрать из файла рифму к указанному слову.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main()
{
	system("chcp 1251 > 0");

	std::vector<std::string> words; // массив для хранения слов из файла
	std::string value; // наше слово
	std::string file; // фаил для чтения
	std::string str;  // строка для хранения слов из файла

	std::cout << "введите слово: ";
	std::getline(std::cin, value);

	std::cout << "введите название файла: ";
	std::getline(std::cin, file);

	file += ".txt";

	std::ifstream fin(file); // открываем фаил для чтения

	if (fin.good())
	{
		while (!fin.eof())
		{
			std::getline(fin, str);
			if (str != "") words.push_back(str);
		}

		fin.close();

		for (auto& element : words)
			if (value[value.length() - 1] == element[element.length() - 1] &&
				value[value.length() - 2] == element[element.length() - 2])
				std::cout << "\nрифма для слова " << value << " - " << element << "\n";

		words.~vector();
	}

	else std::cout << "\nОшибка, не удалось открыть фаил - " << file << "\n";

}
