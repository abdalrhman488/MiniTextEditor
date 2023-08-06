#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <cctype>




using namespace std;

fstream myFile;

//File & DS
vector<string> Lines;
vector<int> LinesNumber;
bool isLoaded = false;

void display_all()
{
	if (Lines.empty()) {
		cout << "The File is Empty, No Data to Show !" << endl;
		cout << "---------------------------------" << endl;
	}
	else {
		for (int i = 0; i < Lines.size(); i++) {
			cout << LinesNumber[i] << " " << Lines[i] << endl;
		}
		cout << "---------------------------------" << endl;
		cout << "Proccesss Ended Successfully..." << endl;
		cout << "---------------------------------" << endl;
	}
}

void add_line(int &LineNumber,string inputLine)
{
	LineNumber++;
	cout << "Enter The line : " << endl;

	cin.ignore();
	getline(cin, inputLine);

	Lines.push_back(inputLine);
	LinesNumber.push_back(LineNumber);
	cout << "---------------------------------" << endl;
	cout << "Proccesss Ended Successfully..." << endl;
	cout << "---------------------------------" << endl;

}

void get_line(int choosen_line)
{
	if (Lines.empty()) {
		{
			cout << "The File is Empty, Please Enter Data first!" << endl;
			cout << "---------------------------------" << endl;
		}
	}
	else {
		bool found = false;
		cout << "Enter Chosen Line : ";
		cin >> choosen_line;
		while (cin.fail()) {
			cout << "Please Enter A Number..... \n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> choosen_line;
		}
		for (int i = 0; i < Lines.size(); i++) {
			if (choosen_line == LinesNumber[i]) {
				cout << "Line " << LinesNumber[i] << " : " << Lines[i] << endl;
				found = true;
				break;
			}
		}
		if (found == false) {
			cout << "Line Does Not Exist.....\n";
			cout << "---------------------------------" << endl;
		}
		else {
			cout << "---------------------------------" << endl;
			cout << "Proccesss Ended Successfully..." << endl;
			cout << "---------------------------------" << endl;
		}

	}
}

void delete_line(int choosenLine , int &lineNumber)
{
	if (Lines.empty())
	{
		cout << "The File is Empty, No Data to Delete !" << endl;
		cout << "---------------------------------" << endl;
	}
	else {
		bool found = false;
		cout << "Enter Chosen Line : ";
		cin >> choosenLine;
		while (cin.fail()) {
			cout << "Please Enter A Number..... \n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> choosenLine;
		}
		for (int i = 0; i < Lines.size(); i++) {
			if (choosenLine == LinesNumber[i]) {
				if (choosenLine == Lines.size()) {
					Lines.pop_back();
					LinesNumber.pop_back();
					lineNumber--;
					found = true;
					cout << "Line Deleted Successfully....\n";
					break;
				}
				else {
					for (int j = choosenLine - 1; j < Lines.size() - 1; j++) {
						Lines[j] = Lines[j + 1];
					}
					Lines.pop_back();
					LinesNumber.pop_back();
					lineNumber--;
					found = true;
					cout << "---------------------------------" << endl;
					cout << "Line Deleted Successfully....\n";
					break;
				}
			}
		}
		if (found == false) {
			cout << "Line Does Not Exist.....\n";
			cout << "---------------------------------" << endl;
		}
		else {
			cout << "---------------------------------" << endl;
		}
	}
}

void insert_line(int choosenLine, int &lineNumber)
{
	if (Lines.empty())
	{
		cout << "The File is Empty, No Data to Delete !" << endl;
		cout << "---------------------------------" << endl;
	}
	else {
		bool found = false;
		cout << "Enter Chosen Line : ";
		cin >> choosenLine;
		while (cin.fail()) {
			cout << "Please Enter A Number..... \n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> choosenLine;
		}
		string insrtd;
		cout << "Enter Inserted Line : ";
		cin.ignore();
		getline(cin, insrtd);
		string temp;
		for (int i = 0; i < Lines.size(); i++) {
			if (choosenLine == LinesNumber[i]) {
				if (choosenLine == Lines.size()) {
					lineNumber++;
					temp = Lines[i];
					Lines[i] = insrtd;
					LinesNumber.push_back(lineNumber);
					Lines.push_back(temp);
					found = true;
					cout << "---------------------------------" << endl;
					cout << "Line inserted Successfully....\n";
					break;
				}
				else {
					lineNumber++;
					LinesNumber.push_back(lineNumber);
					Lines.push_back(" ");
					for (int j = Lines.size() - 1; j > choosenLine - 1; j--) {
						Lines[j] = Lines[j - 1];
					}
					Lines[choosenLine - 1] = insrtd;
					found = true;
					cout << "---------------------------------" << endl;
					cout << "Line inserted Successfully....\n";
					break;
				}
			}
		}
		if (found == false) {
			cout << "Line Does Not Exist.....\n";
			cout << "---------------------------------" << endl;
		}
		else {
			cout << "---------------------------------" << endl;
		}
	}
}

void update_line(int choosenLine, string updatedLine)
{
	cout << "Enter Chosen Line : ";
	cin >> choosenLine;
	while (cin.fail()) {
		cout << "Please Enter A Number..... \n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> choosenLine;
	}
	cout << "Enter Updated Line : ";
	cin.ignore();
	getline(cin, updatedLine);
	cout << "---------------------------------" << endl;
	bool found = false;
	for (int i = 0; i < Lines.size(); i++) {
		if (choosenLine == LinesNumber[i]) {
			Lines[i] = updatedLine;
			found = true;
			break;
		}
	}
	if (found == false) {
		cout << "Line Does Not Exist.....\n";
		cout << "---------------------------------" << endl;
	}
	else {
		cout << "---------------------------------" << endl;
		cout << "Line Updated Successfuly....." << endl;
		cout << "---------------------------------" << endl;
	}
}

void find_and_replace(string searched , string replaced)
{
	bool found = false;
	cout << "Enter Text to Replace: ";
	cin.ignore();
	getline(cin, searched);
	cout << "Enter New Text : ";
	//cin.ignore();
	getline(cin, replaced);
	for (int i = 0; i < Lines.size(); i++) {
		if (Lines[i].find(searched) != string::npos) {
			Lines[i].replace(Lines[i].find(searched), searched.length(), replaced);
			i = i - 1;
			found = true;
		}

	}
	if (found == false) {
		cout << "Searched Text Does Not Exist.....\n";
		cout << "---------------------------------" << endl;
	}
	else {
		cout << "---------------------------------" << endl;
		cout << "Text Replaced Successfully......" << endl;
		cout << "---------------------------------" << endl;
	}
}

void find_lines_numbers(string searched)
{
	bool found = false;
	cout << "Enter Text to Search For : ";
	cin.ignore();
	getline(cin, searched);
	for (int i = 0; i < Lines.size(); i++) {
		if (Lines[i].find(searched) != string::npos) {
			cout << searched << " is found in line : " << LinesNumber[i] << "\n";
			found = true;
		}

	}
	if (found == false) {
		cout << "Searched Text Does Not Exist.....\n";
		cout << "---------------------------------" << endl;
	}
	else {
		cout << "---------------------------------" << endl;
		cout << "Proccess Ended Successfully...." << endl;
		cout << "---------------------------------" << endl;
	}
}

int main()
{
	//Variables
	bool exitFlag = true;
	int Choice;
	
	string lineOrder;

	//case1; 
	string input;
	int Ln = 0;

	//case2
	int choosenLine = 0; 

	//case5
	string updtLine;

	//case7 
	string srchd; //case 6
	string replaced; 
	if (!isLoaded) {
		myFile.open("Text.txt", ios::in);
		if (myFile.is_open())
		{
			string ReadLine;

			while (getline(myFile, ReadLine)) {
				size_t unt = 0;
				unt = ReadLine.find(" ");
				lineOrder = ReadLine.substr(0, unt);
				Ln = stoi(lineOrder);
				ReadLine.erase(0, lineOrder.length() + 1);
				LinesNumber.push_back(Ln);
				Lines.push_back(ReadLine);
			}
			myFile.close();
		}
	}
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	cout << "					*********************************************" << endl;
	cout << "					| ---Welcome to Mini Text Editor GEN_107--- |" << endl;
	cout << "					*********************************************" << endl;

	while (exitFlag)
	{	
		cout << "---------------------------------" << endl;
		cout << "| 1: To Add new Line		|" << endl;
		cout << "---------------------------------" << endl;
		cout << "| 2: To Get Line Text		|" << endl;
		cout << "---------------------------------" << endl;
		cout << "| 3: To Delete Line		|" << endl;
		cout << "---------------------------------" << endl;
		cout << "| 4: To Insert Line		|" << endl;
		cout << "---------------------------------" << endl;
		cout << "| 5: To Update Line		|" << endl;
		cout << "---------------------------------" << endl;
		cout << "| 6: To Find Lines Numbers	|" << endl;
		cout << "---------------------------------" << endl;
		cout << "| 7: To Find and Replace	|" << endl;
		cout << "---------------------------------" << endl;
		cout << "| 8: To Display All Lines	|" << endl;
		cout << "---------------------------------" << endl;
		cout << "| 9: To Exit                    |" << endl;
		cout << "---------------------------------" << endl;
		cout << "					Please Enter Your Choice : ";
		cin >> Choice;

		while (cin.fail()) {
			cout << "					You Entered Invalid Choice , Please Try Again...\n";
			cin.clear();
			cin.ignore(256 , '\n');
			isLoaded = true;
			return main();
		}
		switch (Choice)
		{
		case 1:
			add_line(Ln, input); 
			break;
		case 2:
			get_line(choosenLine); 
			break;
		case 3:
			delete_line(choosenLine, Ln); 
			break;
		case 4:
			insert_line(choosenLine, Ln);
			break;
		case 5:
			update_line(choosenLine, updtLine); 
			break;
		case 6:
			find_lines_numbers(srchd); 
			break;
		case 7:
			find_and_replace(srchd, replaced); 
			break;
		case 8:
			display_all(); 
			break;
		case 9:
			myFile.open("Text.txt", ios::out);
			if (myFile.is_open()) {
				for (int i=0; i < Lines.size(); i++) {
					myFile << LinesNumber[i] << " " << Lines[i] << endl;
				}
				myFile.close();
			}
			cout << "Bye Bye......" << endl;
			exitFlag = false;
			break;
		default:
			cout << "					You Entered Invalid Choice , Please Try Again...\n";
			isLoaded = true;
			return main();
			break;
		}

	}

}