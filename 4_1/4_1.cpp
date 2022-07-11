#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class address
{
private:
	string city​_name;
	string street_name;
	int house_number = -999;
	int apartment_number = -999;

public:
	address()
	{
		string city;
		string street;
		int house_num = -999;
		int apart_num = -999;
	}
	address(string city​_name, string street_name, int house_number, int apartment_number)
	{
		this->city​_name = city​_name;
		this->street_name = street_name;
		this->house_number = house_number;
		this->apartment_number = apartment_number;
	}
	string print_address()
	{
		return this->city​_name + ", " + this->street_name + ", " + to_string(this->house_number) + ", " + to_string(this->apartment_number);
	}

};

int main()
{
	setlocale(LC_ALL, "Rus");

	int number_of_addresses = -999;

	ifstream fin("in.txt");
	ofstream out("out.txt");

	fin.open("in.txt");
	if (fin.is_open())
	{
		string city;
		string street;
		int house_num = -999;
		int apart_num = -999;

		fin >> number_of_addresses;

		address** arr = new address* [number_of_addresses];
		for (int i = 0; i < number_of_addresses; i++)
		{
			arr[i] = new address[4];
		}

		out.open("out.txt");
		if (out.is_open())
		{

			for (int i = 0; i < number_of_addresses; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					fin >> city;
					fin >> street;
					fin >> house_num;
					fin >> apart_num;
					arr[i][j] = address(city, street, house_num, apart_num);
				}
			}

			out << number_of_addresses << endl;
			for (int i = number_of_addresses - 1; i >= 0; i--)
			{
				for (int j = 0; j < 4; j++)
				{
					out << arr[i][j].print_address() << endl;
				}
			}

			fin.close();
			out.close();

			for (int i = 0; i < number_of_addresses; i++)
			{
				delete[] arr[i];
			}
			delete[] arr;
		}

		else
		{
			cout << "Не удалось открыть файл";
			return -1;
		}
	}

	else
	{
		cout << "Не удалось открыть файл";
		return -1;
	}
}