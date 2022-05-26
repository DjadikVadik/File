
//  4.Программа, генерирует числа от 0 до 999. Трёхзначные записывает в один файл, 
//  двузначные в другой, а, состоящие из одной цифры, в третий.Запись и генерация 
//  останавливаются тогда, когда в каждом файле есть как минимум по 10 значений.
//  Во всех трёх файлах значения необходимо отсортировать по возрастанию.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
	system("chcp 1251 > 0");
	srand(time(0));
	int n1 = 0; // однозначные числа
	int n2 = 0; // двузначные числа
	int n3 = 0; // трехзначные числа

	std::vector<int> od;  // однозначные числа
	std::vector<int> dv;  // двузначные числа
	std::vector<int> tr;  // трехзначные числа

	do
	{
		int x = rand() % 1000;

		if (x < 10) {
			n1++;
			od.push_back(x);
		}

		else if (x < 100) {
			n2++;
			dv.push_back(x);
		}

		else if (x < 1000) {
			n3++;
			tr.push_back(x);
		}

	} while (n1 < 10 || n2 < 10 || n3 < 10);

	std::sort(od.begin(), od.end());  // сортируем все 3 массива
	std::sort(dv.begin(), dv.end());
	std::sort(tr.begin(), tr.end());

	std::ofstream of_1("однозначные числа.txt", std::ios::app); // откраваем соответствующие файлы
	std::ofstream of_2("двузначные числа.txt", std::ios::app);
	std::ofstream of_3("трехзначные числа.txt", std::ios::app);

	for (auto& i : od)         // копруем данные в файлы
		of_1 << i << "\n";

	for (auto& i : dv)         // копруем данные в файлы
		of_2 << i << "\n";

	for (auto& i : tr)         // копруем данные в файлы
		of_3 << i << "\n";

	od.~vector(); // чистим память от данных
	dv.~vector();
	tr.~vector();

	of_1.close();  // закрываем потоки
	of_2.close();
	of_3.close();
}