#include <iostream>
#include <cmath>
#include <iomanip>

void displayoption();		   //R3
int showInformation();		   //R4
int searchStudent();		   //R5
int articulationManagement(); //R6
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
	cout << "*****************************" << endl;
	cout << "Ente yor option (1-5):" ;

	int option= 0;
	cin >> option;
	switch(option)
	{
	case 1:
		cout << showInformation();
		break;
	case 2:
		cout << searchStudent();
		break;
	case 3:
		cout << articulationManagement();
		break;
	case 4:
		cout << "(4) Export student list";
	case 5:
		//cout << leave() ; (function for leave(),)
		break;
	default:
		cout << "error option!!Please enter 1-5";
	}
}

int showInformation() //R4
{
	int a;
	classabv a;
	vector
	vector<string> a;
	msg_vec.push_back("Show Information Menu");
	msg_vec.push_back("Show student information (A to Z)");
	msg_vec.push_back("Show programme information (Descending cutoff GPA)")
	
	vector<string> func_vec;
	func_vec.push_back("Show Student Information");
	
	
	menu(msg_vec,func_vec);
}

int searchStudent()//R5
{
	char studentName;
	cout << "Student Name";
	cin >> studentName;
	cout << "No of subj. taken:" << endl;
	cout << "No of offers: " << endl;


}

int articulationManagement()   //R6
{
	cout << "**** Articulation Management Menu **** " << endl;
	cout << "(1) Assign offers to students" << endl;
	cout << "(2) Reset offers" <<endl;
	cout << "**************************************" << endl;
	cout << "Enter your option (1 - 2):" << endl; 
	int option;
	cin >> option;
	return option;
}
