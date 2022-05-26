
//  1.Создать набор текстовых файлов по темам.Например, один файл - цветы, 
//  другой – животные.Пользователь с клавиатуры вводит  существительное и тему.
//  Слово помещается в тот файл, теме которого соответствует.Если файла с 
//  такой темой нет, он создаётся и слово помещается в него.

#include <iostream>
#include <vector>
#include <fstream>
#include <string>


int main()
{
	system("chcp 1251 > 0");

	std::vector<std::string> themes;
	std::string value;
	std::string name;

	do {
		system("cls");
		int x;
		std::cout << "Для ввода нвого слова введите 1, для выхода введите 0: ";
		std::cin >> x;
		std::cin.ignore(32767, '\n');

		if (x == 1)
		{
			std::cout << "\nВведите существительное: ";
			std::getline(std::cin, value);
			std::cout << "\nВведите тему: ";
			std::getline(std::cin, name);
			std::string file_name = name + ".txt";

			bool exist = false;

			for (auto& i : themes)
				if (name == i)
				{
					exist = true;
					std::ofstream of(file_name, std::ios::app);
					of << value << "\n";
					of.close();
				}

			if (!exist)
			{
				themes.push_back(name);
				std::ofstream of(file_name, std::ios::app);
				of << value << "\n";
				of.close();
			}
		}

		else if (x == 0) break;

		else std::cout << "\nВы ввели некоректное значение!!!\n";

	} while (true);
}