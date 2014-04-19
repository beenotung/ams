#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;


void displayoption();											 //R3
int showInformation();											 //R4
void searchStudent();											 //R5
void searchStudent2();                                           //R5 part2
void articulationManagement();									 //R6
void exportStudent_list();										 //R7


int main()
{
	displayoption(); //R2
	return 0;
}
void displayoption() //R3
{
	cout << "****** AMS System Menu ******" << endl; 
	cout << " (1) Show information" << endl; 
	cout << " (2) Search student " << endl;
	cout << " (3) Articulation management" << endl; 
	cout << " (4) Export student list" << endl ;
	cout << " (5) Quit" << endl; 
	cout << "*****************************" << endl;
	cout << "Ente yor option (1-5):" ;

	int option = 0;
	cin >> option;
	switch(option)
	{
	case 1:
		cout << showInformation(); 
		break;
	case 2:
		searchStudent();
		break;
	case 3:
		articulationManagement();
		break;
	case 4:
		exportStudent_list();
	case 5:   //the program will ciose directly
		//leave();
		break;
	default:
		cout << "error option!!Please enter 1-5";
	}
}

int showInformation() //R4
{
	cout << "****** Show Information Menu ******" << endl; 
	cout << "(1) Show student information (A to Z)" << endl; 
	cout << "(2) Show programme information (Descending cutoff GPA)" << endl; 
	cout << "*********************************** " << endl; 
	cout << "Enter your option (1 - 2):";

	int option = 0;
	cin >> option;
	return option;

}

void searchStudent()//R5 part 1
{
	string studentName;
	cout << "Student Name: ";
	cin >> studentName;
	searchStudent2();

	cout << "******* Student Action Menu ******** " << endl;
	cout << "(1) Update GPA and No. of subjects " << endl;
	cout << "(2) Enter grade point of each extra subject and recalculate GPA " << endl;
	cout << "(3) Show student's details" << endl;
	cout << "(4) Show possible programmes" << endl;
	cout << "(5) Back to system menu" << endl; 
	cout << "************************************" << endl;
	
	int option;
	cout << "Enter your option: ";
	cin >> option;
	
	switch (option)
	{
	case 1:
		cout << "R9";
		break;
	case 2:
		cout << "R10";
		break;
	case 3:
		cout << "R11";
		break;
	case 4:
		cout << "R12";
		break;
	case 5:
		cout << "R13";
		break;
	}
}

void searchStudent2()           //R5 part 2
{
	cout << "Student ID: " << "(done other function)"  << endl;
	cout << "Cumulative GPA: " << "(done other function)" << endl;
	cout << "No. of subj. taken: " << "(done other function)" << endl;
	cout << "Offers: " << "(done other function)" << endl << endl; 
}

void articulationManagement()   //R6
{
	cout << "**** Articulation Management Menu **** " << endl;
	cout << "(1) Assign offers to students" << endl;
	cout << "(2) Reset offers" <<endl;
	cout << "**************************************" << endl;
	cout << "Enter your option (1 - 2):";
	int option;
	cout << "Enter your option";
	cin >> option;
	switch (option)
	{
	case 1:
		cout << "R14-R16";
		break;
	case 2:
		cout << "R17";
		break;
	}
}

void exportStudent_list()//R7
{
	string programme_code,filename;
	cout << "Enter the Programming code:";
	cin >> programme_code;
	cout << "Enter the filename to export :";
	cin >> filename;
}
