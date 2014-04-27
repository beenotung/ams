#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class student
{
	int rollno;
	char name[50];
	char offer[50];
	double cgpa, subjno, offerno;
public:
	void getdata();
};
void student::getdata()													// Create Student Record, NOT USED
{
	cout<<"\nEnter Student ID: ";
	cin>>rollno;
	cout<<"\n\nEnter Student Name: ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nCumulative GPA: ";
	cin>>cgpa;
	cout<<"\nNo. of Subj. taken: ";
	cin>>subjno;
	cout<<"\nOffers: ";
	cin.ignore();
	cin.getline(offer,50);
	cout<<"\nNo. of offers: ";
	cin>>offerno;
}
void write_student();	//write the record in binary file
int main()
{
	write_student();
	return 0;
}
void write_student()		// Create Student Record, NOT USED
{
	student st;
	ofstream outFile;
	outFile.open("student_test.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}