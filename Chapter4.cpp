// Chapter4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <array>

using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::array;

void clear();
void pause();
int persinfo();
int arr();
int singlestring();
int singlestringstr();
int candybar();
int candybararr();
int pizzanalysis();
int pizzanalysispt();
int candybararrpt();
int fortyard();

void clear()
{
	system("CLS");
	std::cout.flush();
}

void pause()
{
	cout << "\n";
	system("PAUSE");
}

int persinfo()
{
	clear();
	cout << "Enter your first name: ";
	string fname;
	getline(cin, fname);
	cout << "Enter your last name: ";
	string lname;
	getline(cin, lname);
	cout << "Enter the letter grade you deserve: ";
	char grade;
	cin >> grade;
	cin.clear();
	if (grade > 68 || grade < 65) grade = 70;
	cin.ignore(1000, '\n');
	grade++;
	if (grade > 68 || grade < 65) grade = 70;
	cout << "Enter your age: ";
	int age;
	cin >> age;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "\nName: " << lname << ", " << fname << "\nGrade: " << grade << "\nAge: " << age;
	pause();
	return 0;
}

int arr()
{
	clear();
	string name;
	string dessert;
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter your favorite dessert: ";
	getline(cin, dessert);
	cout << "I have some deleicious " << dessert << " for you, " << name << ".\n";
	pause();
	return 0;
}

int singlestring()
{
	clear();
	cout << "Enter your first name: ";
	char fname[20];
	cin.getline(fname, 20);
	cout << "Enter your last name: ";
	char lname[20];
	cin.getline(lname, 20);
	char name[43]{};
	std::strcat(name, lname);
	std::strcat(name, ", ");
	std::strcat(name, fname);
	cout << "Here's the information in a single string:\n" << name;
	pause();
	return 0;
}

int singlestringstr()
{
	clear();
	cout << "Enter your first name: ";
	string fname;
	getline(cin, fname);
	cout << "Enter your last name: ";
	string lname;
	getline(cin, lname);
	string name = lname + ", " + fname;
	cout << "Here's the information in a single string:\n" << name;
	pause();
	return 0;
}

int candybar()
{
	clear();
	struct CandyBar
	{
		string brand;
		double weight;
		int calories;
	} bar{"Mocha Munch", 2.3, 350};
	cout << "Brand: " << bar.brand << "\nWeight: " << bar.weight << "\nCalories: " << bar.calories;
	pause();
	return 0;
}

int candybararr()
{
	clear();
	struct CandyBar
	{
		string brand;
		double weight;
		int calories;
	};
	CandyBar bars[3]{ {"Snickers", 1.2, 300}, {"Milky Way", 1.0, 250}, {"KitKat", 1.4, 350} };
	for (int i = 0; i < 3; i++)
	{
		cout << "Brand: " << bars[i].brand << ", Weight: " << bars[i].weight << ", Calories: " << bars[i].calories << std::endl;
	}
	pause();
	return 0;
}

int pizzanalysis()
{
	clear();
	struct pizza
	{
		string company;
		double diameter;
		double weight;
	} pie {};
	cout << "Enter the name of the pizza company: ";
	getline(cin, pie.company);
	cout << "Enter the diameter of the pizza: ";
	cin >> pie.diameter;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Enter the weight of the pizza: ";
	cin >> pie.weight;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Company: " << pie.company << "\nDiameter: " << pie.diameter << "\nWeight: " << pie.weight;
	pause();
	return 0;
}

int pizzanalysispt()
{
	clear();
	struct pizza
	{
		string company;
		double diameter;
		double weight;
	};
	pizza* pie = new pizza{};
	cout << "Enter the name of the pizza company: ";
	getline(cin, pie->company);
	cout << "Enter the diameter of the pizza: ";
	cin >> pie->diameter;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Enter the weight of the pizza: ";
	cin >> pie->weight;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Company: " << pie->company << "\nDiameter: " << pie->diameter << "\nWeight: " << pie->weight;
	pause();
	delete pie;
	return 0;
}

int candybararrpt()
{
	clear();
	struct CandyBar
	{
		string brand;
		double weight;
		int calories;
	};
	const CandyBar* bars = new CandyBar[3]{ { "Snickers", 1.2, 300 },{ "Milky Way", 1.0, 250 },{ "KitKat", 1.4, 350 } };
	for (int i = 0; i < 3; i++)
	{
		cout << "Brand: " << bars[i].brand << ", Weight: " << bars[i].weight << ", Calories: " << bars[i].calories << std::endl;
	}
	delete[] bars;
	pause();
	return 0;
}

int fortyard()
{
	clear();
	array<double, 3> times {};
	cout << "Enter the first time in seconds: ";
	cin >> times[0];
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Enter the second time in seconds: ";
	cin >> times[1];
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Enter the third time in seconds: ";
	cin >> times[2];
	cin.clear();
	cin.ignore(100, '\n');
	double avg = (times[0] + times[1] + times[2]) / 3;
	cout << "Average time: " << avg;
	pause();
	return 0;
}

int main()
{
	while (true)
	{
		cout << "1. Personal Info\n2. Name and Dessert\n3. Single String with Chars"
			<< "\n4. Single String with std::string\n5. Candy Bar Struct"
			<< "\n6. Candy Bar Struct Array\n7. Pizza Analysis"
			<< "\n8. Pizza Analysis Pointer\n9. Candy Bar Struct Array Pointer"
			<< "\n10. 40 yd Dash Average Times\n11. Quit\n> ";
		int c;
		cin >> c;
		cin.ignore(100, '\n');
		if (c == 1) c  = persinfo();
		if (c == 2) c  = arr();
		if (c == 3) c  = singlestring();
		if (c == 4) c  = singlestringstr();
		if (c == 5) c  = candybar();
		if (c == 6) c  = candybararr();
		if (c == 7) c  = pizzanalysis();
		if (c == 8) c  = pizzanalysispt();
		if (c == 9) c  = candybararrpt();
		if (c == 10) c = fortyard();
		if (c == 11) break;
		cin.clear();
		clear();
	}
    return 0;
}

