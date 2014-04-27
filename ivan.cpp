/*
 * AMS v0.1
 */
 
// including header

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <ctime>

using namespace std;


//================================================================//


// declearing utility functions

string to_string (int a);

#ifdef linux
void goup();
void goup(int n);
void godown();
void godown(int n);
void goright();
void goright(int n);
void goleft();
void goleft(int n);
string prel();
void gorow(int n);
void gotoxy(int x, int y);
#elif _WIN32
#include <windows.h>
void gotoxy(int xpos, int ypos);
#endif

string man_string(string ori,int n);

string space(int n,char c);
string space(int n);

string lsr(string l, char c, string r, int n);
string lsr(string l,string r,int n);
string lsr(string l,string r);

string center(string target,int count,char filling);
string center(string target,int count);
string center(string target,char filling);
string center(string target);

void delay(int time);

void warming(string);

ifstream loadfile(string filename,int count);
ifstream loadfile(string filename);


// declearing class

class GroupMemberRec{
public:
   string name,id;
};

class GroupMemberClass
{
public:
   GroupMemberClass();
   void add(string name,string id);
   void show();
private:
   vector<GroupMemberRec> GroupMemberList;
};


// declearing main functions

void welcome();

void loadfromfile();

// declearing variable

GroupMemberClass GroupMember;


//================================================================//


// defining utility functions

string to_string (int a)
{
   ostringstream temp;
   temp<<a;
   return temp.str();
}

#ifdef linux
void goup(){
   cout << "\x1b[A";
}
void goup(int n){
   cout << "\x1b["+to_string(n)+"A";
}
void godown(){
   cout << "\x1b[B";
}
void godown(int n){
   cout << "\x1b["+to_string(n)+"B";
}
void goright(){
   cout << "\x1b[C";
}
void goright(int n){
   cout << "\x1b["+to_string(n)+"C";
}
void goleft(){
   cout << "\x1b[D";
}
void goleft(int n){
   cout << "\x1b["+to_string(n)+"D";
}
string prel(){
   return "\x1b[F";
}
void gorow(int n){
   cout << "\x1b"+to_string(n)+"[G";
}
void gotoxy(int x, int y){
   cout << "\x1b["+to_string(y)+';'+to_string(x)+"H";
}
#elif _WIN32
#include <windows.h>
void gotoxy(int xpos, int ypos){
   COORD scrn;
   HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
   scrn.X = xpos; scrn.Y = ypos;
   SetConsoleCursorPosition(hOuput,scrn);
}
#endif

string man_string(string ori,int n)
{
   string temp="";
   for(int i=0;i<n;i++)
   {
      temp+=ori;
   }
   return temp;
}

string space(int n,char c)
{
   string temp="";
   for(int i=0;i<n;i++)
   {
      temp+=c;
   }
   return temp;
}
string space(int n)
{
   return space(n,' ');
}

string lsr(string l,char c,string r,int n)
{
   return (l+space((n-l.length()-r.length()),c)+r);
}
string lsr(string l,string r,int n)
{
   return lsr(l,' ',r,n);
}
string lsr(string l,string r)
{
   return lsr(l,r,80);
}

string center(string target,int count,char filling){
   while (target.length()<(unsigned)count) {
      target=filling+target;
      if (target.length()<(unsigned)count) target += filling;
   }
   return target;
}
string center(string target,int count){
   return center(target,count,' ');
}
string center(string target,char filling){
   return center(target,80,filling);
}
string center(string target){
   return center(target,80,' ');
}

void delay(int time){
   clock_t now=clock();

   while(clock()-now<time);
}

void warming(string msg){
   cout<<msg;
}






// defining class

GroupMemberClass::GroupMemberClass(void){
   this->add("Tung Cheung Leong","13058536A");
   this->add("Tai Leung Kin","12171480A");
   this->add("Au Wai Ki","12657346A");
   this->add("ivan","");
}

void GroupMemberClass::add(string name,string id){
   GroupMemberRec newmember;
   newmember.name=name;
   newmember.id=id;
   GroupMemberList.push_back(newmember);
}

void GroupMemberClass::show(){
   cout<<endl<<center(center("Group Member List",40,'-'))<<endl;
   for(unsigned int i=0;i<GroupMemberList.size();i++){
      cout<<center(lsr(GroupMemberList[i].name,GroupMemberList[i].id,40))<<endl;
   }
}


// defining main functions

void welcome(){
   cout<<center("Welcome!",'=');
   cout<<center("CCN2042 Computer Programming");
   cout<<center("Group Assignment - Articulation Management System");

   cout<<endl;
   GroupMember.show();
   cout<<center(center("-",40,'-'));
}




//================================================================//


// standard program entire point

// ivan class

class student
{
	int rollno;
	char name[50];
	char offer[50];
	double cgpa, subjno, offerno;
public:
	void show_tabular() const;
	void showdata() const;
	int retrollno() const;
};

void student::show_tabular() const										// Show Student Information 1
{
	cout<<rollno<<"A"<<setw(6)<<" "<<name<<setw(10)<<cgpa<<setw(4)<<subjno<<setw(4)<<offer<<setw(4)<<offerno<<endl;
}

void student::showdata() const											// Show Student Information 2
{
	cout<<"\n\tStudent ID: "<<rollno<<"A";
	cout<<"\n\tStudent Name: "<<name;
	cout<<"\n\tCumulative GPA: "<<cgpa;
	cout<<"\n\tNo. of Subj. taken: "<<subjno;
	cout<<"\n\tOffers: "<<offer;
	cout<<"\n\tNo. of offers: "<<offerno;
}

int  student::retrollno() const											// For Access
{
	return rollno;
}

void menu();
void show1();		// Student Information 1
void show2();			// Student Information 2
void content4();
void search_student(int);
void content2();

int main()
{
   welcome();

   cout<<man_string("\n",2);

   ///loadfromfile();


   //leave();
   cout<<center("normal end");

   cin.get();
   menu();

}

void menu()
{										
	char ch;
	do {
	system("cls");											
	cout<<"\n\n\n\t****** AMS System Menu ******\n\n";
	cout<<"\n\n\t(1) Show Information 1";
	cout<<"\n\n\t(6) Show Information 2";
	cout<<"\n\n\t(2) Search Student";
	cout<<"\n\n\t(3) Articulation Management";
	cout<<"\n\n\t(4) Export Student List";
	cout<<"\n\n\t(5) Quit";
	cout<<"\n\n\tEnter Your Option (1 - 5): ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
		case '1': show1(); break;	
		case '6': show2(); break;	
		case '2': content2(); break;	
		//case '3': content3(); break;
		case '4': content4(); break;
		case '5': break;
		default: cout<<"/a";
	}
    }while(ch!='5');
}

void show1()		// Student Information 1
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\tShow Information \n\n";
	cout<<"===============================================================================\n";
	cout<<"Student ID       Student Name        CGPA   Subj.No.   Offers   OfferNo."<<endl;
	cout<<"===============================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.show_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}

void show2()			// Student Information 2
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tStudent Information\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void content4()
{
	char filemem[50];
	char filename[50];
	system("cls");
	cout<<"\n\n\n\t****** Export Student List ******";
	cout<<"\n\n\tEnter Programme Code:";
	cin.ignore();
	cin.getline(filemem,50);
	cout<<"\n\tEnter filename to export to:";
	cin.getline(filename,50);

	ofstream myfile;
	myfile.open (filename);
	myfile << filemem << "\n";
	myfile.close();

	cout<<"\n\n\tExport Students Successfully";
	cin.get();
}

void content2()
{
	int num;
	cout<<"\n\n\n\t\tSearch Student";
	cout<<"\n\n\n\n\tEnter Student ID: "; cin>>num;
	search_student(num);
}

void search_student(int n)		// Search Student
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.retrollno()==n)
		{
	  		 st.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}