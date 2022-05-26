
//  7.Создать класс СПРАВОЧНИК со следующими полями : Название фирмы, 
//  Владелец, Телефон, Адрес, Род деятельности.Реализовать следующие 
//  возможности : Поиск по названию, Поиск по владельцу, Поиск по номеру телефона, 
//  Поиск по роду деятельности, Показ всех записей и добавление.Вся информация, 
//  естественно, хранится в файле с возможностью дозаписи.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class BuyerGuide {
private:

	struct Buyer {    // структура "торговая точка"

		std::string name;  // название фирмы
		std::string owner; // владелец
		std::string telefon;  // телефон
		std::string address; // адресс
		std::string workname; // род деятельности
	};

	std::vector<Buyer> buyers;  // колекция торговых точек

public:
	void push_guide(); // запись справочника в фаил
	void clone_guide(); // чтение справочника из файла
	void new_buyer();  // метод добавления новой торговой точки
	void search_name();   // поиск торговой точки по названию
	void search_owner();   // поиск торговой точки по владельцу
	void search_telefon();   // поиск торговой точки по телефону
	void search_workname(); // поиск торговой точки по роду деятельности
	void show_all();  // показ всех торговых точек
};


int main()
{
	system("chcp 1251 > 0");

	
}

void BuyerGuide::push_guide()
{
	std::ofstream fout("Guide.baze");

	if (fout.good())
	{
		int size = buyers.size();
		fout.write((char*)&size, sizeof(int)); // записываем размер вектора

		for (auto& i : buyers)
		{
			int name_len = i.name.length() + 1;
			fout.write((char*)& name_len, sizeof(int)); // записываем длинну строк (полей класса)

			int owner_len = i.owner.length() + 1;
			fout.write((char*)& owner_len, sizeof(int)); // записываем длинну строк (полей класса)

			int telefon_len = i.telefon.length() + 1;
			fout.write((char*)& telefon_len, sizeof(int)); // записываем длинну строк (полей класса)

			int address_len = i.address.length() + 1;
			fout.write((char*)& address_len, sizeof(int)); // записываем длинну строк (полей класса)

			int workname_len = i.workname.length() + 1;
			fout.write((char*)& workname_len, sizeof(int)); // записываем длинну строк (полей класса)

			fout.write(i.name.c_str(), name_len); // записываем сами строки (поля класса)
			fout.write(i.owner.c_str(), owner_len); // записываем сами строки (поля класса)
			fout.write(i.telefon.c_str(), telefon_len); // записываем сами строки (поля класса)
			fout.write(i.address.c_str(), address_len); // записываем сами строки (поля класса)
			fout.write(i.workname.c_str(), workname_len); // записываем сами строки (поля класса)
		}
		fout.close();
	}

	else std::cout << "\nФаил не удалось открыть!!!";
}

void BuyerGuide::clone_guide()
{
	std::ifstream fin("Guide.baze");

	if (fin.good())
	{
		int size = 0; // переменная количества элементов вектора
		fin.read((char*)& size, sizeof(int)); //  считываем это количество

		for (int i = 0; i < size; i++)
		{
			int name_len = 0; //переменные хранящие длинну строк
			int owner_len = 0; //переменные хранящие длинну строк
			int telefon_len = 0; //переменные хранящие длинну строк
			int address_len = 0; //переменные хранящие длинну строк
			int workname_len = 0; //переменные хранящие длинну строк

			fin.read((char*)&name_len, sizeof(int)); //  считываем это количество
			fin.read((char*)&owner_len, sizeof(int)); //  считываем это количество
			fin.read((char*)&telefon_len, sizeof(int)); //  считываем это количество
			fin.read((char*)&address_len, sizeof(int)); //  считываем это количество
			fin.read((char*)&workname_len, sizeof(int)); //  считываем это количество

			Buyer b;   // создаем объект класса для заполнения его полей
			char buf[50]; //создаем буфер для копирования строк

			fin.read(buf, name_len); // считываем строки (поля класса)
			b.name = buf;

			fin.read(buf, owner_len); // считываем строки (поля класса)
			b.owner = buf;

			fin.read(buf, telefon_len); // считываем строки (поля класса)
			b.telefon = buf;

			fin.read(buf, address_len); // считываем строки (поля класса)
			b.address = buf;

			fin.read(buf, workname_len); // считываем строки (поля класса)
			b.workname = buf;

			buyers.push_back(b);
		}

		fin.close();
	}

	else std::cout << "\nФаил не удалось открыть, или он еще не был создан!!!";
}

void BuyerGuide::new_buyer()
{
	Buyer buyer;
	std::string value;

	std::cout << "\nвведите название фирмы : ";
	std::getline(std::cin, value);
	buyer.name = value;

	std::cout << "\nвведите имя владельца фирмы : ";
	std::getline(std::cin, value);
	buyer.owner = value;

	std::cout << "\nвведите телефон фирмы : ";
	std::getline(std::cin, value);
	buyer.telefon = value;

	std::cout << "\nвведите адресс фирмы : ";
	std::getline(std::cin, value);
	buyer.address = value;

	std::cout << "\nвведите род деятельности фирмы : ";
	std::getline(std::cin, value);
	buyer.workname = value;

	buyers.push_back(buyer);
}

void BuyerGuide::search_name()
{
	std::cout << "\nвведите название фирмы для поиска : ";
	std::string name;
	std::getline(std::cin, name);

	for (auto& i : buyers)
	{
		if (i.name == name)
			std::cout << "------------------------------------------\n"
			<< "название     : " << i.name << "\n"
			<< "владелец     : " << i.owner << "\n"
			<< "телефон      : " << i.telefon << "\n"
			<< "адресс       : " << i.address << "\n"
			<< "деятельность : " << i.workname << "\n";
	}
}

void BuyerGuide::search_owner()
{
	std::cout << "\nвведите имя владельца фирмы для поиска : ";
	std::string owner;
	std::getline(std::cin, owner);

	for (auto& i : buyers)
	{
		if (i.owner == owner)
			std::cout << "------------------------------------------\n"
			<< "название     : " << i.name << "\n"
			<< "владелец     : " << i.owner << "\n"
			<< "телефон      : " << i.telefon << "\n"
			<< "адресс       : " << i.address << "\n"
			<< "деятельность : " << i.workname << "\n";
	}
}

void BuyerGuide::search_telefon()
{
	std::cout << "\nвведите телефон фирмы для поиска : ";
	std::string telefon;
	std::getline(std::cin, telefon);

	for (auto& i : buyers)
	{
		if (i.telefon == telefon)
			std::cout << "------------------------------------------\n"
			<< "название     : " << i.name << "\n"
			<< "владелец     : " << i.owner << "\n"
			<< "телефон      : " << i.telefon << "\n"
			<< "адресс       : " << i.address << "\n"
			<< "деятельность : " << i.workname << "\n";
	}
}

void BuyerGuide::search_workname()
{
	std::cout << "\nвведите род деятельности фирмы для поиска : ";
	std::string workname;
	std::getline(std::cin, workname);

	for (auto& i : buyers)
	{
		if (i.workname == workname)
			std::cout << "------------------------------------------\n"
			<< "название     : " << i.name << "\n"
			<< "владелец     : " << i.owner << "\n"
			<< "телефон      : " << i.telefon << "\n"
			<< "адресс       : " << i.address << "\n"
			<< "деятельность : " << i.workname << "\n";
	}
}

void BuyerGuide::show_all()
{
	for (auto& i : buyers)
	{
		std::cout << "------------------------------------------\n"
			<< "название     : " << i.name << "\n"
			<< "владелец     : " << i.owner << "\n"
			<< "телефон      : " << i.telefon << "\n"
			<< "адресс       : " << i.address << "\n"
			<< "деятельность : " << i.workname << "\n";
	}
}