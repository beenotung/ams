/*
 * AMS v0.1.5
 */

// magic numbers
#define STURECFILENAME "StudentRecords.txt"
#define PRORECFILENAME "ProgrammeRecords.txt"

// including header

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
void cls();
#elif _WIN32
#include <windows.h>
void gotoxy(int xpos, int ypos);
#endif

string man_string(string ori,int n);
/*copy the item with number n and return the new string
eg:string str=man_string("abc",3);
str == "abcabcabc"
*/

string space(int n,char c);
/*produce char c with number of n
and return new string
*/
string space(int n);
/*produce [space] with number of n
and return new string
*/

string lsr(string l, char c, string r, int n);
/*produce a new string with leftmost part as l
rightmost part as r
and use (n-(lenght of l)-(length of r))of char c to fill the middle path
*/
string lsr(string l,string r,int n);
/*produce a new string with leftmost part as l
rightmost part as r
and use (n-(lenght of l)-(length of r))of [space] to fill the middle path
*/
string lsr(string l,string r);
/*produce a new string with leftmost part as l
rightmost part as r
and use (80-(lenght of l)-(length of r))of [space] to fill the middle path
*/

string center(string target,int count,char filling);
/*make a new string of count char
and put the targert in the center of the new string
and fill the unassigned leftmost part and rightmost part with char filling
and return the new string
*/
string center(string target,int count);
/*make a new string of count char
and put the targert in the center of the new string
and fill the unassigned leftmost part and rightmost part with char [space]
and return the new string
*/
string center(string target,char filling);
/*make a new string of 80 char
and put the targert in the center of the new string
and fill the unassigned leftmost part and rightmost part with char filling
and return the new string
*/
string center(string target);
/*make a new string of 80 char
and put the targert in the center of the new string
and fill the unassigned leftmost part and rightmost part with char [space]
and return the new string
*/

void delay(int time);				//wait for time mini-second

void warming(string);				//output expected error

int leave(string msg);				//leave the problem with message msg

bool fexists(const char *filename);	//check where the file exist or not

bool loadifile(ifstream &file, const char *filename, int count);	//load the  input file with count times
bool loadifile(ifstream &file, const char *filename);				//loadthe input file with 10 times
bool loadofile(ifstream &file, const char *filename, int count);	//load the output file with count times
bool loadofile(ifstream &file, const char *filename);				//loadthe output file with 10 times

// declearing menu functions
void showmenu(vector<string> msg_list,vector<string> func_list);
void loadfileErrMenu(string filename);//out error msg in menue interface

// declearing class

struct GroupMemberRec
{
    string name,id;
};

class GroupMemberClass
{
public:
    GroupMemberClass(void);
    void add(string name,string id);		//add member
    void show();							//show member
private:
    vector<GroupMemberRec> GroupMemberList;	//vector,store groupmember id and name
};


struct StuNameRec
{
    string fullName,nickName;
};
class StudentRecClass
{
public:

    bool setName(char mode, string data);               //dispose
    bool setName(string fullName, string nickName);     //dispose
    /* set/get single name or both supported
    * single :
    *  a : index
    * &b : name-data
    * both :
    * &a : fullname-data
    * &b : nickname-data
    */
    bool setID(string);
    bool setName(string);
    bool setPro(string);
    bool setGPA(float);
    bool setNum(int);

    bool getName(char mode, string data);                                   //dispose
    bool getName(string fullName, string nickName);//similar to setName     //dispose
    bool getID(string);
    bool getName(string);
    bool getPro(string);
    bool getGPA(float);
    bool getNum(int);

    void show();                            		//show student data in this record (one student only)

private:
    StuNameRec name;                                //dispose
    string Name;
    string ID;
    vector<string> ProChoice;
    vector<string> Offer;
    float GPA;
    int Num;										// Number of subjects taken
};
class StudentClass
{
public:
    StudentClass(void);
private:
    vector<StudentRecClass> StudentData;			//vector,store st record
    int index;
};


// declearing main functions

void welcome();		//R1

void loadrecfile();	//R2


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
void goup()
{
    cout << "\x1b[A";
}
void goup(int n)
{
    cout << "\x1b["+to_string(n)+"A";
}
void godown()
{
    cout << "\x1b[B";
}
void godown(int n)
{
    cout << "\x1b["+to_string(n)+"B";
}
void goright()
{
    cout << "\x1b[C";
}
void goright(int n)
{
    cout << "\x1b["+to_string(n)+"C";
}
void goleft()
{
    cout << "\x1b[D";
}
void goleft(int n)
{
    cout << "\x1b["+to_string(n)+"D";
}
string prel()
{
    return "\x1b[F";
}
void gorow(int n)
{
    cout << "\x1b"+to_string(n)+"[G";
}
void gotoxy(int x, int y)
{
    cout << "\x1b["+to_string(y)+';'+to_string(x)+"H";
}
void cls()
{
    for (int i=0; i<25; i++) cout<<endl;
}
#elif _WIN32
#include <windows.h>
void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}
#endif

string man_string(string ori,int n)
{
    string temp="";
    for(int i=0; i<n; i++)
    {
        temp+=ori;
    }
    return temp;
}

string space(int n,char c)
{
    string temp="";
    for(int i=0; i<n; i++)
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

string center(string target,int count,char filling)
{
    while (target.length()<(unsigned)count)
    {
        target=filling+target;
        if (target.length()<(unsigned)count) target += filling;
    }
    return target;
}
string center(string target,int count)
{
    return center(target,count,' ');
}
string center(string target,char filling)
{
    return center(target,80,filling);
}
string center(string target)
{
    return center(target,80,' ');
}

void delay(int time)
{
    clock_t now=clock();

    while(clock()-now<time);
}

void warming(string msg)
{
    cout<<msg;
}

int leave(string msg)
{
    cout<<"\nEnter a char to leave...";
    char c;
    cin>>c;
    cout<<endl<<center(msg);
    return 1;
}

bool fexists(const char *filename)
{
    ifstream ifile(filename);
    return ifile;
}

bool loadifile(ifstream &file, const char *filename, int count)
{
    if (fexists(filename))
    {
        file.open(filename);
        return file.is_open();
    }
    else
    {
        string msg="\n"+(string)filename+" is currently not readable!";
        if (count>1)
        {
            msg+=" retrying "+to_string(--count)+" time";
            msg=(count>1)?msg+"s":msg;
            warming(msg);
            return loadifile(file,filename,count);
        }
        else
        {
            warming(msg+" Please check!");
            return false;
        }
    }
}
bool loadifile(ifstream &file, const char *filename)
{
    return loadifile(file,filename,10);
}
bool loadofile(ifstream &file, const char *filename, int count)
{
    file.open(filename);
    if (fexists(filename))
    {
        return file.is_open();
    }
    else
    {
        string msg="\n"+(string)filename+" is currently not accesable!";
        if (count>1)
        {
            msg+=" retrying "+to_string(--count)+" time";
            msg=(count>1)?msg+"s":msg;
            warming(msg);
            return loadofile(file,filename,count);
        }
        else
        {
            warming(msg+" Please check!");
            return false;
        }
    }
}
bool loadofile(ifstream &file, const char *filename)
{
    return loadofile(file,filename,10);
}




// defining class
/*---- GroupMemberClass methods ----*/
GroupMemberClass::GroupMemberClass(void)
{
    this->add("Tung Cheung Leong","13058536A");
    this->add("Au Wai Ki","12657346A");
    this->add("Ko Tsz Wai","13080101A");
    this->add("Kung Ho Yin","13498425A");
    this->add("Tai Leung Kin","12171480A");
}
void GroupMemberClass::add(string name,string id)
{
    GroupMemberRec newmember;
    newmember.name=name;
    newmember.id=id;
    GroupMemberList.push_back(newmember);
}
void GroupMemberClass::show()
{
    cout<<endl<<center(center("Group Member List",40,'-'))<<endl;
    for(unsigned int i=0; i<GroupMemberList.size(); i++)
    {
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



   cout<<center("press [Enter] to continue...");

   cin.get();
   menu();


   leave("normal end");
}

void menu()
{
	char ch;
	do {
    cls();
	cout<<"\n\n\n\t****** AMS System Menu ******\n\n";
	cout<<"\n\n\t(1) Show Information 1";
	cout<<"\n\n\t(6) Show Information 2";
	cout<<"\n\n\t(2) Search Student";
	cout<<"\n\n\t(3) Articulation Management";
	cout<<"\n\n\t(4) Export Student List";
	cout<<"\n\n\t(5) Quit";
	cout<<"\n\n\tEnter Your Option (1 - 5): ";
	cin>>ch;
    cls();
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
    cls();
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
