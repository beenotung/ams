/*
 * AMS v0.1
 */

// magic numbers
#define STURECFILENAME "StudentRecords..txt"
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


struct StuNameRec{
    string fullName,nickName;
};
class StudentRecClass
{
public:

    bool setName(char mode, string data);
    bool setName(string fullName, string nickName);
    /* set/get single name or both supported
    * single :
    *  a : index
    * &b : name-data
    * both :
    * &a : fullname-data
    * &b : nickname-data
    */
    bool setID(string);
    bool setPro(string);
    bool setGPA(float);
    bool setNum(int);

    bool getName(char mode, string data);
    bool getName(string fullName, string nickName);//similar to setName
    bool getID(string);
    bool getPro(string);
    bool getGPA(float);
    bool getNum(int);

private:
    StuNameRec name;
    string ID;
    vector<string> ProChoice;
    float GPA;
    int Num;										// Number of subjects taken
};
class StudentClass
{
private:
    vector<StudentRecClass> StudentData;			//vector,store st record
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


// defining menu functions
void loadfileErrMenu(string filename)
{
    ///
}




// defining class
///
/// \ GroupMemberClass methods
///
GroupMemberClass::GroupMemberClass(void)
{
    this->add("Tung Cheung Leong","13058536A");
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

///
/// \ StudentRecClass methods
///
bool StudentRecClass::setName(char mode, string data)
{
    switch (mode){
    case 'f':this->name.fullName=data;
        break;
    case 'n':this->name.nickName=data;
        break;
    }
    return true;
}
bool StudentRecClass::setName(string fullName, string nickName)
{
    this->name.fullName=fullName;
    this->name.nickName=nickName;
    return true;
}
bool StudentRecClass::setID(string ID)
{
    this->ID=ID;
    return true;
}
bool StudentRecClass::setGPA(float GPA)
{
    this->GPA=GPA;
    return true;
}
bool StudentRecClass::setNum(int Num)
{
    this->Num=Num;
    return true;
}

bool StudentRecClass::getName(char mode, string data)
{
    switch (mode){
    case 'f':this->data=name.fullName;
        break;
    case 'n':this->data=name.nickName;
        break;
    }
    return true;
}
bool StudentRecClass::getName(string fullName, string nickName)
{
    fullName=this->name.fullName;
    nickName=this->name.nickName;
    return true;
}
StudentRecClass::getID(string ID)
{
    this->ID=ID;
}
StudentRecClass::getGPA(float GPA)
{
    this->GPA=GPA;
}
StudentRecClass::getNum(int Num)
{
    this->Num=Num;
}


// defining main functions

void welcome()
{
    cout<<center("Welcome!",'=');
    cout<<center("CCN2042 Computer Programming");
    cout<<center("Group Assignment - Articulation Management System");

    cout<<endl;
    GroupMember.show();
    cout<<center(center("-",40,'-'));
}

void loadrecfile(ifstream & recfile, string filename)
{
    bool ok;
    ok = loadifile(recfile,filename.c_str());
    cout<<endl<<filename<<" loading ";
    if (ok)
    {
        cout<<"successed";
    }
    else
    {
        cout<<"failed";
        loadfileErrMenu(filename);
    }
}
void loadrecfile()
{
    cout<<"loading files";
    ifstream sturecfile,prorecfile;
    string line;
    loadrecfile(sturecfile,STURECFILENAME);
    loadrecfile(prorecfile,PRORECFILENAME);
    if (!(sturecfile.is_open()&&prorecfile.is_open()))
    {
        exit(2);
    }
    string ID,Name,Pro;
    float GPA;
    int Num;
    while (sturecfile>>ID>>Name>>GPA>>Num>>Pro)
    {
        add
    }
}




//================================================================//


// standard program entire point

int main()
{
    welcome();

    cout<<man_string("\n",2);

    loadrecfile();


    return leave("nornal leave");
}








vector<string> list;
list.push_back(" Student Action Menu ");
list.push_back("Update GPA and No.of subkjects");
list.push_back("Enter ...");

vector<string> function_list;
function_list.push_back("Update GPA");
function_list.push_back("Enter grade");



menu(list);
