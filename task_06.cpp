
// 6.Реализовать сонник.В одном файле слова, в другом определения.
// Осуществить поиск  и показ нужного значения, и добавление новых значений.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void initial_vectors(std::vector<std::string>& words, std::vector<std::string>& meanings, const std::string& file1, const std::string& file2)
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

void set_new_meaning(const std::string& file1, const std::string& file2, const std::string& value)
{
	std::ofstream fout1(file1, std::ios::app);
	std::ofstream fout2(file2, std::ios::app);

	if (fout1.good() && fout2.good())
	{
		fout1 << value << "\n";
		fout1.close();

		std::cout << "\nвведите определение для вашего слова!\n";
		std::string str;
		std::getline(std::cin, str);

		fout2 << str << "\n";
		fout2.close();
	}

	else std::cout << "\nОшибка, не удалось открыть фаилы !!!" << "\n";
}


int main()
{
	system("chcp 1251 > 0");

	std::string value; // наше слово
	std::string file1; // фаил для чтения
	std::string file2;

	std::cout << "введите слово: ";
	std::getline(std::cin, value);

	std::cout << "введите название файла для поиска слов: ";
	std::getline(std::cin, file1);

	file1 += ".txt";

	std::cout << "введите название файла для поиска определения: ";
	std::getline(std::cin, file2);

	file2 += ".txt";

	int n;

	std::cout << "\nесли вы хотите дабавит значение - введите 1\nесли вы хотите найти значение - введите 2\nдля выхода из программы - введите 0\n";
	std::cin >> n;
	std::cin.ignore(32767, '\n');

	if (n == 1) set_new_meaning(file1, file2, value);

	else if (n == 2)
	{
		std::vector<std::string> words; // массив для хранения слов из файла
		std::vector<std::string> meanings; // массивдля хранения значений

		initial_vectors(words, meanings, file1, file2);

		int i = 0;
		for (i; i < words.size(); i++)
			if (words[i] == value) break;

		std::cout << "\nзначение: " << meanings[i] << "\n";
	}

	else std::cout << "\nвы ввели некоректное значение!!!\n\n";
}
