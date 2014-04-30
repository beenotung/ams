/*
 * AMS v0.2
 */

// magic numbers
#define STURECFILENAME "StudentRecords.txt"
#define PRORECFILENAME "ProgrammeRecords.txt"
const int DELAYTIME=2000;

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

bool getint(int &a, string msg1, string msg2);
bool getint(int &a);
/*  the follow steps
 *1. clear cin
 *2. get one int from cin
 *3. clear cin
 *4. return if get int success
*/

string man_string(string ori,int n);
/*copy the item with number n and return the new string
eg:string str=man_string("abc",3);
str == "abcabcabc"
*/

void line(int n);
/*make n new line(s)*/

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

void warning(string);				//output expected error

int leave(string msg);				//leave the problem with message msg

bool fexists(const char *filename);	//check where the file exist or not

bool loadifile(ifstream &file, const char *filename, int count);	//load the  input file with count times
bool loadifile(ifstream &file, const char *filename);				//loadthe input file with 10 times
bool loadofile(ifstream &file, const char *filename, int count);	//load the output file with count times
bool loadofile(ifstream &file, const char *filename);				//loadthe output file with 10 times

// declearing menu functions
void showmenu(vector<string> msg_list);
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
    bool setGPA(float);
    bool setNum(int);
    bool setPro(string);
    bool setOffer(string);

    bool getName(char mode, string &data);                                   //dispose
    bool getName(string &fullName, string &nickName);//similar to setName     //dispose
    bool getID(string &);
    bool getName(string &);
    bool getGPA(float &);
    bool getNum(int &);
    bool getPro(int index, string & data);
    bool getOffer(int index, string & data);
    bool getPro(string & data);
    bool getOffer(string & data);
    //show student data in this record (one student only)
    void showtable();
    void showline();

private:
    StuNameRec name;                            //disposed
    string Name;
    string ID;
    vector<string> ProChoice;
    vector<string> Offer;
    float GPA;
    int Num;									// Number of subjects taken
};
class StudentClass
{
public:
    StudentClass(void);
    vector<StudentRecClass> StudentData;		//vector,store st record
    int index;
    void add(StudentRecClass newRec);           //add new element to StudentData and also update the Index to newest element
    bool searchID(string ID);
    bool searchName(string Name);
    void search();
    void select();                          // call Student Action Menu on the indexed studentrec
    void showAZ();

private:
    int dummyint;
};


// declearing main functions

void welcome();                 //R1

void loadrecfile();             //R2

void AMS_System_Menu();         //R3

void Show_Information_Menu();   //R4


// declearing variable

GroupMemberClass GroupMember;
StudentClass Student;


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

bool getint(int &a, string msg1, string msg2)
{
    cin.clear();
    if (msg1!="")
        cout<<endl<<msg1;
    string str;
    getline(cin,str);
    stringstream ss;
    stringstream ss2;
    ss<<str;
    ss>>a;
    ss2<<a;
    cin.clear();
    if (ss.str()!=ss2.str())
        if (msg2!="")
            cout<<endl<<msg2;
    return (ss.str()==ss2.str());
}
bool getint(int &a)
{
    getint(a,"","");
}

string man_string(string ori,int n)
{
    string temp="";
    for(int i=0; i<n; i++)
    {
        temp+=ori;
    }
    return temp;
}

void line(int n)
{
    cout<<man_string("\n",n);
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

void warning(string msg)
{
    line(2);
    cout<<msg;
    delay(DELAYTIME);
}

int leave(string msg)
{
    cout<<endl<<center(msg);
    cout<<endl<<"Press [Enter] to leave...";
    cin.get();
    cout<<"the program will end soon..";
    delay(DELAYTIME);
    exit(1);
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
            warning(msg);
            return loadifile(file,filename,count);
        }
        else
        {
            warning(msg+" Please check!");
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
            warning(msg);
            return loadofile(file,filename,count);
        }
        else
        {
            warning(msg+" Please check!");
            return false;
        }
    }
}
bool loadofile(ifstream &file, const char *filename)
{
    return loadofile(file,filename,10);
}


// defining menu functions
void showmenu(vector<string> msg_list)
{
    cout<<endl<<center(" "+msg_list[0]+" ",40,'*');
    for (int i=1; (unsigned)i<msg_list.size(); i++)
    {
        cout<<endl<<"("<<i<<") "<<msg_list[i];
    }
    cout<<endl<<center("",40,'*');
    line(25-msg_list.size()-3);
}

void loadfileErrMenu(string filename)
{
    ///
    leave("file *"+filename+"* not avaliable !");
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

/*----- StudentRecClass methods -----*/
bool StudentRecClass::setName(char mode, string data)
{
    switch (mode)
    {
    case 'f':
        this->name.fullName=data;
        break;
    case 'n':
        this->name.nickName=data;
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
bool StudentRecClass::setName(string Name)
{
    this->Name=Name;
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
bool StudentRecClass::setPro(string newdata)
{
    this->ProChoice.push_back(newdata);
    return true;
}
bool StudentRecClass::setOffer(string newdata)
{
    this->Offer.push_back(newdata);
    return true;
}

bool StudentRecClass::getName(char mode, string &data)
{
    switch (mode)
    {
    case 'f':
        data=this->name.fullName;
        break;
    case 'n':
        data=this->name.nickName;
        break;
    }
    return true;
}
bool StudentRecClass::getName(string &fullName, string &nickName)
{
    fullName=this->name.fullName;
    nickName=this->name.nickName;
    return true;
}
bool StudentRecClass::getID(string &ID)
{
    ID=this->ID;
    return true;
}
bool StudentRecClass::getName(string &Name)
{
    Name=this->Name;
    return true;
}
bool StudentRecClass::getGPA(float &GPA)
{
    GPA=this->GPA;
    return true;
}
bool StudentRecClass::getNum(int &Num)
{
    Num=this->Num;
    return true;
}
bool StudentRecClass::getPro(int index, string & data)
{
    data=this->ProChoice[index];
    return true;
}
bool StudentRecClass::getOffer(int index, string & data)
{
    data=this->Offer[index];
    return true;
}
bool StudentRecClass::getPro(string & data)
{
    data="";
    for (int i=0; i<this->ProChoice.size(); i++)
    {
        if (i!=0) data+="\t";
        data+=this->ProChoice[i];
    }
    return true;
}
bool StudentRecClass::getOffer(string & data)
{
    data="";
    for (int i=0; i<this->Offer.size(); i++)
    {
        data+=this->Offer[i]+"\t";
    }
    return true;
}
void StudentRecClass::showtable()
{
    cout<<endl<<"Student Name: "<<this->Name;
    cout<<endl<<"Student ID: "<<this->ID;
    printf("\nCumulative GPA: %f1.2",this->GPA);
    cout<<endl<<"No. of subj. taken: "<<this->Num;
    cout<<endl<<"No. of offers: "<<this->Offer.size();
    cout<<endl<<"Offers: ";
    for (int i=0; (unsigned)i<Offer.size(); i++)
    {
        if (i!=0)
        {
            cout<<", ";
        }
        cout<<Offer[i];
    }
}
void StudentRecClass::showline()
{
    cout<<this->ID;
    cout<<"\t"<<this->Name;
    if (this->Name.size()<15) cout<<"\t";
    cout<<"\t"<<this->GPA;
    if ((unsigned)0<=Offer.size())
    {
    cout<<"\t"<<"Nil";
    }
    else
    {
        for (int i=0; (unsigned)i<Offer.size(); i++)
        {
            if (i!=0)
            {
                cout<<", ";
            }
            cout<<Offer[i];
        }
    }
}

/*---- Student Class methods ----*/
StudentClass::StudentClass(void)
{
    this->index=-1;
    this->StudentData.clear();
}
void StudentClass::add(StudentRecClass newRec)
{
    this->StudentData.push_back(newRec);
    this->index=this->StudentData.size()-1;
}
bool StudentClass::searchID(string ID)
{
    int found=0;
    for (int i=0; (unsigned)i<this->StudentData.size(); i++)
    {
        string dID;
        this->StudentData[i].getID(dID);
        if (dID==ID)
        {
            found++;
            this->index=i;
        }
    }
    return (found>0);
}
bool StudentClass::searchName(string Name)
{
    int found=0;
    for (int i=0; (unsigned)i<this->StudentData.size(); i++)
    {
        string dName;
        this->StudentData[i].getName(dName);
        if (dName==Name)
        {
            found++;
            this->index=i;
        }
    }
    if (found>1)
    {
        cout<<endl<<center(center("Expected issue",20,'!'),40);
        cout<<endl<<"More than one student has this name. Please search by ID for this student...";
    }
    return (found==1);
}
void StudentClass::search()
{
    cout<<endl<<endl<<"Please input student Name or ID: ";
    string input;
    getline(cin,input);
    bool isID=(input.size()==9);
    int i=0;
    while ((isID)&&(i<9))
    {
        isID=((input[i]>='0')&&(input[i]<='9'));
        i++;
    }
    bool found;
    if (isID)
    {
        found=this->searchID(input);
    }
    else
    {
        found=this->searchName(input);
    }
    if (found)
    {
        this->select();
    }
    else
    {
        cout<<endl<<"student *"<<input<<"* is not found..";
    }
}
void StudentClass::select()
{
    /// call menu searched
}
void StudentClass::showAZ()
{
    ///
    //sort A-Z
    //show all

    cout<<endl<<"Student ID\tStudent Name\t\tCGPA\tOffered Prog.";
    cout<<endl<<center("",'-');
    for (int i=0; i<this->StudentData.size();i++)
    {
        StudentRecClass dRec=this->StudentData[i];
        dRec.showline();
        cout<<endl;
    }

        ///
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
    cout<<endl<<"Loading information from files...";
    ifstream sturecfile,prorecfile;
    string line;
    loadrecfile(sturecfile,STURECFILENAME);
    loadrecfile(prorecfile,PRORECFILENAME);
    if (!(sturecfile.is_open()&&prorecfile.is_open()))
    {
        exit(2);
    }
    string ID,Pro;
    //StuNameRec Name;
    string Name;
    float GPA;
    int Num;
    vector<string>ProChoice;
    string oldline="";
    string newline="1";
    do
    {
        oldline=newline;
        getline(sturecfile,newline);
        // read ID
        int i1=0;
        while (newline[i1]!='\t')
        {
            i1++;
        }
        {
            ID="";
            char tmp[9];
            for (int i=0; i<i1; i++)
            {
                tmp[i]=newline[i];
            }
            tmp[i1]='\0';
            ID=tmp;
        }
        // read name
        int i2=i1+1;
        while (newline[i2]!='\t')
        {
            i2++;
        }
        Name="";
        for (int i=i1+1; i<i2; i++)
        {
            Name+=newline[i];
        }
        // read GPA
        int i3=i2+1;
        while (newline[i3]!='\t')
        {
            i3++;
        }
        GPA=0;
        {
            string tmp;
            stringstream ss;
            for (int i=i2+1; i<i3; i++)
            {
                tmp+=newline[i];
            }
            ss<<tmp;
            ss>>GPA;
        }
        // read number of subject taken (Num)
        int i4=i3+1;
        while (newline[i4]!='\t')
        {
            i4++;
        }
        Num=0;
        {
            string tmp;
            stringstream ss;
            for (int i=i3+1; i<i4; i++)
            {
                tmp+=newline[i];
            }
            ss<<tmp;
            ss>>Num;
        }
        // read Programme choices main
        int i5=newline.length();
        ProChoice.clear();
        {
            string tmp;                     //remainding part of input (Program choice(s))
            stringstream ss;
            for (int i=i4+1; i<i5; i++)
            {
                tmp+=newline[i];
            }
            ss<<tmp;
            string element;
            while (ss>>element)
            {
                ProChoice.push_back(element);
            }
        }
        StudentRecClass newRec;
        newRec.setName(Name);
        newRec.setID(ID);
        newRec.setGPA(GPA);
        newRec.setNum(Num);
        for (int i=0; (unsigned)i<ProChoice.size(); i++)
            newRec.setPro(ProChoice[i]);
        Student.add(newRec);
    }
    while (newline!=oldline);
}


void AMS_System_Menu()
{
    int op;
    do
    {
        vector<string> msg_list;
        msg_list.push_back("AMS System Menu");
        msg_list.push_back("Show information");
        msg_list.push_back("Search student");
        msg_list.push_back("Articulation management");
        msg_list.push_back("Export student list");
        msg_list.push_back("Quit");
        showmenu(msg_list);

        while (!getint(op,"Enter Your Option (1 - 5): ",""))
        {
            warning("integer only!");
        }
        switch(op)
        {
        case 1:
            Show_Information_Menu();
            break;
        case 5:
            break;
        default:
            warning("1 to 5 only!");
        }
    }
    while(op!=5);
}

void Show_Information_Menu()
{
    int op;
    do
    {
        vector<string> msg_list;
        msg_list.push_back("Show Information Menu");
        msg_list.push_back("Show student information (A to Z)");
        msg_list.push_back("Show programme information (Descending cutoff GPA)");
        showmenu(msg_list);
        while (!getint(op,"Enter Your Option (1 - 2): ",""))
        {
            warning("integer only!");
        }
        switch(op)
        {
        case 1:
            Student.showAZ();
            break;
        case 2:
            warning("2");
            break;
        default:
            warning("1 to 2 only!");
        }
    }
    while((op!=1)&&(op!=2));
    cout<<endl<<"Press [Enter] to continue..";
    cin.get();
}


//================================================================//


// standard program entire point

int main()
{
    welcome();

    line(1);
    loadrecfile();

    AMS_System_Menu();

    cls();
    return leave("bye bye");
}
