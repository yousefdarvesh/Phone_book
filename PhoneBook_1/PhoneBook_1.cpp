// PhoneBook_1.cpp : Defines the entry point for the console application...
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include<cctype>
using namespace std;
const int MAX_NAMES = 10;
const string PHONEBOOK = "phonebook App";
struct Person

{
		string name;	
		string phone;
		Person()
	{
		name = "";
		phone = "";
	}
		bool Matches(string x)
	{	
		return (name.find(x) != string::npos);
	}		
};

void ReadAllPeople(Person people[], int &num_people)
{	
	ifstream fin;
	fin.open(PHONEBOOK.c_str(), ios::app);
	if (fin.fail())
	{
		cout << "The list is Empty " << PHONEBOOK << endl;
		
			return;
	}
		int i = 0;
		getline(fin, people[i].name);
		while (!fin.eof() && i < MAX_NAMES)	
	{
		getline(fin, people[i].phone);
		i++;
		if (i < MAX_NAMES)
		getline(fin, people[i].name);	
	}
		num_people = i;
		fin.close();
}
void SaveToFile(const Person people[], int num_people)

{
		ofstream fout;
		fout.open(PHONEBOOK.c_str());
		for (int i = 0; i < num_people; i++)	
	{			
		fout << people[i].name << endl;
		fout << people[i].phone << endl;
	}
		}

void AppendToFile(Person person)
{
		ofstream fin;
		fin.open(PHONEBOOK.c_str(), ios::app);
		fin << person.name << endl;
		fin << person.phone << endl;
		fin.close();	
}

void AddName(Person people[], int &num_people)
{
		Person person;
		cout << "\nPlease Enter a Name: ";
		getline(cin, person.name);
		cout << "Please Enter a Phone Number: ";
		getline(cin, person.phone);
	for (int i = 0; i < num_people; i++)
	{
		if (i + 1 == num_people)
			people[num_people] = person;
	}
		num_people++;
		AppendToFile(person);
		cout << "\n The Enter has been saved " << endl;
}

void ListAllNames(const Person people[], int num_people)
{
		cout << "\nList of all records:\n";
		for (int i = 0; i < num_people; i++)
		cout << people[i].name << " - " << people[i].phone << endl;
}
void main()

{
		Person people[MAX_NAMES];
		int num_people;
		ReadAllPeople(people, num_people);		
		char choice;
	do
	{
		cout << "[A]dd new entery -- enter A\n";
		cout << "[D]display-- enter D\n";
		cout << "[Q]uit-- enter Q\n\n";
		cout << "Choice? ";
		cin >> choice;
		cin.get();   
		choice = toupper(choice);	
		switch (choice)	
		{
			case 'A':   AddName(people, num_people);        break;	
			case 'D':   ListAllNames(people, num_people);   break;
		}
	} while (choice != 'Q' && choice != 'q');
}
