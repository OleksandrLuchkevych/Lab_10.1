#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateTXT(char* fname) // створення файлу з введених рядків
{
	ofstream fout(fname); // відкрили файл для запису
	string s; // введений користувачем рядок
	
		cin.get(); // очищуємо буфер клавіатури – щоб не було символу
		cin.sync(); // "кінець рядка", який залишився після вводу числа
		cout << "enter line: "; getline(cin, s); // ввели рядок
		fout << s << endl; // записали його у файл
		
	
}
void PrintTXT(char* fname) // виведення файлу на екран
{
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl; // виводимо його на екран
	}
	cout << endl;
}
int SearchTXT(char* fname)
{
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитане слово
	int k = 0; // кількість слів
		while (getline(fin, s)) // поки можна прочитати слово
		{
			for(int i = 0; s[i]!=0; i++)
				if (s[i] == '.')
				{
					k++; // збільшили кількість
					if (k == 3)
						return i;
				}
		}
	return k;
}

int main()
{
	// text files
	char fname[100]; // ім'я файлу
	cout << "enter file name: "; cin >> fname;
	CreateTXT(fname); // ввели рядки файлу з клавіатури
	PrintTXT(fname); // вивели вміст файлу на екран
	cout << "index of 3 dot = " << SearchTXT(fname) << endl;
	return 0;
}