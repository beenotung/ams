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
int leave(string msg);

bool fexists(const char *filename);

bool loadifile(ifstream &file, const char *filename, int count);
bool loadifile(ifstream &file, const char *filename);
bool loadofile(ifstream &file, const char *filename, int count);
bool loadofile(ifstream &file, const char *filename);


// declearing menu functions
void loadfileErrMenu(string filename);

// declearing class

struct GroupMemberRec
{
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

/* set/get single name or both supported
 * single :
 *  a : index
 * &b : name-data
 * both :
 * &a : fullname-data
 * &b : nickname-data
*/
struct StuNameRec{
    string fullName,nickName;
};
class StudentRec
{
public:

    bool setName(string  a, string &b);
    bool setName(string &a, string &b);
    bool setID(string);
    bool setPro(string);
    bool setGPA(float);
    bool setNum(int);

    bool getName(string  a, string &b);
    bool getName(string &a, string &b);
    bool getID(string);
    bool getPro(string);
    bool getGPA(float);
    bool getNum(int);
private:
    StuNameRec name;
    string ID;
    vector<string> ProChoice;
    float GPA;
    int Num;
};


// declearing main functions

void welcome();

void loadrecfile();


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

class StuNameRec{
public:
    string fullName,nickName;
};
void GroupMemberClass::add(string name,string id)
{

}

class StudentRec
{
public:

    bool setName(string  a, string &b);
    bool setName(string &a, string &b);
    bool setID(string);
    bool setPro(string);
    bool setGPA(float);
    bool setNum(int);

    bool getName(string  a, string &b);
    bool getName(string &a, string &b);
    bool getID(string);
    bool getPro(string);
    bool getGPA(float);
    bool getNum(int);
private:
    StuNameRec name;
    string ID;
    vector<string> ProChoice;
    float GPA;
    int Num;
};


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

