
// 11. Создать файл, в который будут собраны одинаковые предложения из двух других файлов, созданных заранее.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


typedef std::vector<std::string> vec_s;

void initial_vectors(vec_s& str_file1, vec_s& str_file2, const std::string& file1, const std::string& file2)
{
	std::string str;  // строка для хранения предложений
	std::ifstream fin1(file1); // открываем фаил для чтения
	std::ifstream fin2(file2); // открываем фаил для чтения

	if (fin1.good() && fin2.good())
	{
		char ch; // символ для считывания файла посимвольно
		while (fin1.get(ch))
		{
			if (ch == '.' || ch == '!' || ch == '?')
			{
				str += ch;
				str_file1.push_back(str);
				str = "";
			}
			else if (ch == '\n') continue;
			else str += ch;
		}

		fin1.close();

		str = "";

		while (fin2.get(ch))
		{
			if (ch == '.' || ch == '!' || ch == '?')
			{
				str += ch;
				str_file2.push_back(str);
				str = "";
			}
			else if (ch == '\n') continue;
			else str += ch;
		}

		fin2.close();
	}

	else std::cout << "\nОшибка, не удалось открыть фаилы !!!" << "\n";
}

int main()
{
	system("chcp 1251 > 0");
	srand(time(0));

	std::string file1, file2; // две строки содержащие имена файлов
	vec_s str_file1, str_file2; // два вектора стрингов содержащие предложения этих файлов
	
	std::cout << "Введите название 1го файла: ";
	std::getline(std::cin, file1);

	std::cout << "Введите название 2го файла: ";
	std::getline(std::cin, file2);

	file1 += ".txt";
	file2 += ".txt";

	initial_vectors(str_file1, str_file2, file1, file2); // заполняем векторы 

	std::string file3; // название файла для хранения общих предложений

	std::cout << "Введите название 3го файла: ";
	std::getline(std::cin, file3);
	file3 += ".txt";

	std::ofstream fout(file3);

	if (fout.good())
	{
		for (auto i : str_file1)
		{
			for (auto j : str_file2)
				if (i == j) fout << i << "\n";
		}

		fout.close();
	}

	else std::cout << "Ошибка!!! не удалось открыть фаил " << file3 << "!!!\n";
}