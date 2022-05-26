
// 12.Написать приложение, которое будет составлять новые смешные слова(без рисунков!) вроде «пенопласточки» 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

	std::string file1; // строка содержащая имя файла
	std::vector<std::string> str_file; // вектор стрингов содержащий слова из файла

	std::cout << "Введите название файла со словами: ";
	std::getline(std::cin, file1);
	file1 += ".txt";

	initial_vectors(str_file, file1);

	std::string file2; // строка содержащая имя файла для хранения готовых смешных слов
	std::cout << "Введите название файла с готовыми смешными словами: ";
	std::getline(std::cin, file2);
	file2 += ".txt";

	std::ofstream fout(file2, std::ios::app);

	std::string str; // строка для хранения готовых смешных слов

	for (int i = 0; i < str_file.size() - 1; i++)
	{
		for (int j = i + 1; j < str_file.size(); j++)
		{
			if (str_file[i].length() >= 2 && str_file[j].length() >= 2      // сли длинна первого и второго слова больше 2ух символов
				&& str_file[i][str_file[i].length() - 2] == str_file[j][0]      // если пооследние 2 буквы первого слова равны первым 2ум буквам второго слова
				&& str_file[i][str_file[i].length() - 1] == str_file[j][1])
			{
				str = str_file[i];
				for (int k = 2; k < str_file[j].length(); k++) str += str_file[j][k];
				fout << str << "\n";
			}

			else if (str_file[i].length() >= 3 && str_file[j].length() >= 3      // сли длинна первого и второго слова больше 3х символов
				&& str_file[i][str_file[i].length() - 3] == str_file[j][0]      // если пооследние 3 буквы первого слова равны первым 3м буквам второго слова
				&& str_file[i][str_file[i].length() - 2] == str_file[j][1]
				&& str_file[i][str_file[i].length() - 1] == str_file[j][2])
			{
				str = str_file[i];
				for (int k = 3; k < str_file[j].length(); k++) str += str_file[j][k];
				fout << str << "\n";
			}

			else if (str_file[i].length() >= 4 && str_file[j].length() >= 4      // сли длинна первого и второго слова больше 4х символов
				&& str_file[i][str_file[i].length() - 4] == str_file[j][0]
				&& str_file[i][str_file[i].length() - 3] == str_file[j][1]      // если пооследние 4 буквы первого слова равны первым 4м буквам второго слова
				&& str_file[i][str_file[i].length() - 2] == str_file[j][2]
				&& str_file[i][str_file[i].length() - 1] == str_file[j][3])
			{
				str = str_file[i];
				for (int k = 4; k < str_file[j].length(); k++) str += str_file[j][k];
				fout << str << "\n";
			}

			else if (str_file[i].length() >= 4 && str_file[j].length() >= 4      // сли длинна первого и второго слова больше 5ти символов
				&& str_file[i][str_file[i].length() - 5] == str_file[j][0]
				&& str_file[i][str_file[i].length() - 4] == str_file[j][1]      // если пооследние 5 букв первого слова равны первым 5ти буквам второго слова
				&& str_file[i][str_file[i].length() - 3] == str_file[j][2]
				&& str_file[i][str_file[i].length() - 2] == str_file[j][3]
				&& str_file[i][str_file[i].length() - 1] == str_file[j][4])
			{
				str = str_file[i];
				for (int k = 5; k < str_file[j].length(); k++) str += str_file[j][k];
				fout << str << "\n";
			}
		}
	}

	fout.close();
}

