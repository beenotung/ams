#include <iostream>
#include <cmath>
#include <iomanip>

void displayoption();   //R3
int showInformation(); //R4
using namespace std;


int main()
{
	displayoption();
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
	cout << "*****************************" << endl;	cout << "Ente yor option (1-5):" ;

	int option= 0;
	cin >> option;
	switch(option)
	{
	case 1:
		cout << showInformation();
		break;
	case 2:
		cout << "Search Student";
		break;
	case 3:
		cout << " (3) Articulation management" ;
		break;
	case 4:
		cout << "(4) Export student list";
	case 5:
		cout << "Quit" ;
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
	cout << "Enter your option (1 - 2):"  << endl;	int option = 0;	cin >> option;	return option;

}

