


/*

please
input the student ID without A, .e.g.
12345678


*/


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

void cls(){
    for (int i=0;i<25;i++)
        cout<<endl;
}

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

bool isID(string input);

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

GroupMemberClass GroupMember;



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
    return getint(a,"","");
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
//    delay(DELAYTIME);
}

int leave(string msg)
{
    cout<<endl<<center(msg);
    cout<<endl<<"Press [Enter] to leave...";
    cin.get();
    cout<<"the program will end soon..";
//    delay(DELAYTIME);
//    exit(1);
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

bool isID(string input)
{
    bool ok=(input.size()==9);
    int i=0;
    while ((ok)&&(i<8))
    {
        ok=((input[i]>='0')&&(input[i]<='9'));
        i++;
    }
    ok=ok&&((input[8]=='A')||(input[8]=='a')||(input[8]=='S')||(input[8]=='s'));
    return ok;
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

//***************************************************************
//    	Programme Class , Programme Class , Programme Class
//****************************************************************
class prog
{
	char univ;
	char pname[50];
	char pcode[50];
	int quota, vacancy;
	double cutoff;
public:
	void getprog();
	void showprog() const;
	void show_tabular2() const;
	char retrollno2() const;
};
void prog::getprog()														// Create Programme Record, NOT USED
{
	cout<<"Remarks: 1-HKU, 2-CUHK, 3-HKUST, 4-PolyU, 5-CityU, 6-HKBU\n";
	cout<<"\nEnter University: ";
	cin>>univ;
	cout<<"\n\nEnter Programme Name: ";
	cin.ignore();
	cin.getline(pname,50);
	cout<<"\nEnter Prog. Code: ";
	cin.ignore();
	cin.getline(pcode,50);
	cout<<"\nEnter Quota: ";
	cin>>quota;
	cout<<"\nEnter Vacancy: ";
	cin>>vacancy;
	cout<<"\nEnter Cutoff GPA: ";
	cin>>cutoff;
}

void prog::showprog() const													// Show Programme Information 1
{
	cout<<"\n\tUniversity: ";
	switch (univ)
	{
	case '1': cout<<"HKU"; break;
	case '2': cout<<"CUHK"; break;
	case '3': cout<<"HKUST"; break;
	case '4': cout<<"PolyU"; break;
	case '5': cout<<"CityU"; break;
	case '6': cout<<"HKBU"; break;
	default: cout<<"/a";
	}
	cout<<"\n\tProgramme Name: "<<pname;
	cout<<"\n\tProg. Code: "<<pcode;
	cout<<"\n\tQuota: "<<quota;
	cout<<"\n\tVacancy: "<<vacancy;
	cout<<"\n\tCutoff GPA: "<<cutoff;
}

void prog::show_tabular2() const											// Show Programme Information 2
{
	switch (univ)
	{
		case '1': cout<<"HKU"; break;
		case '2': cout<<"CUHK"; break;
		case '3': cout<<"HKUST"; break;
		case '4': cout<<"PolyU"; break;
		case '5': cout<<"CityU"; break;
		case '6': cout<<"HKBU"; break;
		default: cout<<"/a";
	}
	cout<<setw(6)<<" "<<pname<<setw(10)<<pcode<<setw(4)<<quota<<setw(4)<<vacancy<<setw(4)<<cutoff<<endl;
}

char prog::retrollno2() const
{
	return univ;
}
//***************************************************************
//    	Programme Class , Programme Class , Programme Class
//****************************************************************

//***************************************************************
//    	Student Class , Student Class , Student Class
//****************************************************************
class student
{
	int rollno;
	char name[50];
	char offer[50];
	double cgpa, subjno, offerno;
public:
	void getdata();
	void getdata2();
	void getoffer();
	void showdata() const;
	void showdata2() const;
	void showdata3() const;
	void showoffer() const;
	void show_tabular() const;
	int retrollno() const;
};

void student::getdata()													// Create Student Record, NOT USED
{
    cout<<"\nenter student ID (without \"A\"): ";
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
void student::getdata2()												// Update GPA
{
    cout<<"\nenter student ID (without \"A\"): ";
	cin>>rollno;
	cout<<"\nUpdate GPA: ";
	cin>>cgpa;
	cout<<"\nUpdate No. of Subj.: ";
	cin>>subjno;
}
void student::getoffer()												// Assign / Update Offers
{
    cout<<"\nenter student ID (without \"A\"): ";
	cin>>rollno;
	cout<<"\nEnter Offers to be Assigned to "<<rollno<<" : ";
	cin.ignore();
	cin.getline(offer,50);
	cout<<"\nEnter No. of Offers to be Assigned: ";
	cin>>offerno;
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
void student::showdata2() const											// Show Updated GPA
{
	cout<<"\n\tStudent ID: "<<rollno<<"A";
	cout<<"\n\tUpdated GPA: "<<cgpa;
	cout<<"\n\tUpdated No. of Subj.: "<<subjno;
}
void student::showdata3() const											// Show Possible Programme
{
	cout<<"\n\tStudent ID: "<<rollno<<"A";
	cout<<"\n\tPossible Prog.: "<<offer;
	cout<<"\n\tNo. of Possible Prog.: "<<offerno;
}
void student::showoffer() const											// Show Assigned Offers
{
	cout<<"\n\tStudent ID: "<<rollno<<"A";
	cout<<"\n\tOffer Assigned: "<<offer;
	cout<<"\n\tNo. of Offer Assigned: "<<offerno;
}
void student::show_tabular() const										// Show Student Information 1
{
	cout<<rollno<<"A"<<setw(6)<<" "<<name<<setw(10)<<cgpa<<setw(4)<<subjno<<setw(4)<<offer<<setw(4)<<offerno<<endl;
}

int  student::retrollno() const											// For Access
{
	return rollno;
}
//***************************************************************
//    	Student Class , Student Class , Student Class
//****************************************************************

//***************************************************************
//    	Declare Function, Declare Function, Declare Function
//****************************************************************
void class_result();		// Student Information 1
void display_all();			// Student Information 2
void display_sp(int);		// Search Student
void write_student();		// Create Student Record, NOT USED
void modify_student(int);	// Modify Studnet Record, NOT USED
void modify_student2(int);	// Update GPA
void result1();				// (1)
void result2();				// (2)
void continue2();			// continue(2)
void result3();				// (3)
void result4();				// (4)
void prog_result();			// Programme Information 1
void display_pall();		// Programme Information 2
void possible_prog(int);	// Possible Programme
void write_prog();			// Create Programme Record, NOT USED
void prog_sp(int);			// Search Programme
void search_prog();			// Search Prog.
void modify_offer(int);		// Assign / Update Offer
//***************************************************************
//    	Declare Function, Declare Function, Declare Function
//****************************************************************

void welcome()
{
    cout<<center("Welcome!",'=');
    cout<<center("CCN2042 Computer Programming");
    cout<<center("Group Assignment - Articulation Management System");

    cout<<endl;
    GroupMember.show();
    cout<<center(center("-",40,'-'));
}

int main()
{
   welcome();				// Welcome Message

//***************************************************************
//    	Ivan Ivan Ivan Ivan Ivan Ivan Ivan Ivan Ivan Ivan Ivan
//****************************************************************
   	cin.get();
	char ch;
	do {
    cls();
	cout<<"\n\n\n\t****** AMS System Menu ******\n\n";
	cout<<"\n\n\t(1) Show Information";
	cout<<"\n\n\t(2) Search Student";
	cout<<"\n\n\t(3) Articulation Management";
	cout<<"\n\n\t(4) Export Student List";
	cout<<"\n\n\t(5) Quit";
	cout<<"\n\n\tEnter Your Option (1 - 5): ";
	cin>>ch;
    cls();
	switch(ch)
		{
			case '1': result1(); break;
			case '2': result2(); break;
			case '3': result3(); break;
			case '4': result4(); break;
			case '5': break;
			default: cout<<"/a";
		}
    }while(ch!='5');
	return 0;
}
void result1()					// (1)
{
	char ch;
    cls();
	cout<<"\n\n\n\t****** Show Information Menu ******";
	cout<<"\n\n\n\t(1) Student Information 1";
	cout<<"\n\n\t(2) Student Information 2";
	cout<<"\n\n\t(3) Programme Information 1";
	cout<<"\n\n\t(4) Programme Information 2";
	cout<<"\n\n\t(5) Search Programme";
	cout<<"\n\n\t*****************************";
	cout<<"\n\n\n\tEnter Your Option (1 - 3): ";
	cin>>ch;
    cls();
	switch(ch)
		{
			case '1':	class_result(); break;
			case '2':	display_all(); break;
			case '3':	prog_result(); break;
			case '4':	display_pall(); break;
			case '5':	search_prog(); break;
			default:	cout<<"\a";
		}
}

void search_prog()			// Search Programme
{
	char num;
	cout<<"Remarks: 1-HKU, 2-CUHK, 3-HKUST, 4-PolyU, 5-CityU, 6-HKBU\n";
	cout<<"\n\n\tEnter University: ";
	cin>>num;
	prog_sp(num);
}

void result2()				// (2)
{
	int num;
    cout<<"\n\n\tenter student ID (without \"A\"): "; cin>>num;
	display_sp(num);
	continue2();
}

void continue2()			// continue(2)
{
	char ch;
	int num;
	cout<<"\n\n\n\t****** Student Action Menu ******";
	cout<<"\n\n\n\t(1) Update GPA and No. of Subj.";
	//cout<<"\n\n\t(2) Enter grade point of each extra subj. for recalculate GPA";
	//cout<<"\n\n\t(3) Student's Details";
	cout<<"\n\n\t(4) Possible Programmes";
	cout<<"\n\n\t(5) Back to system menu";
	cout<<"\n\n\t*****************************";
	cout<<"\n\n\n\tEnter Your Option (1 - 5): ";
	cin>>ch;
    cls();
	switch(ch)
		{
            case '1':	cout<<"\n\n\tenter student ID (without \"A\"): "; cin>>num;
						modify_student2(num); break;
			case '2':	break;
            //case '3':	cout<<"\n\n\tenter student ID (without \"A\"): "; cin>>num;
			//			display_sp(num); break;
            case '4':	cout<<"\n\n\tenter student ID (without \"A\"): "; cin>>num;
						possible_prog(num); break;
			case '5':	break;
			default:	cout<<"\a";
		}
}

void result3()				// (3)
{
	char ch;
	int num;
    cls();
	cout<<"\n\n\n\t****** Articulation Management Menu ******";
	cout<<"\n\n\n\t(1) Assign offers to Students";
	cout<<"\n\n\t*****************************";
	cout<<"\n\n\n\tEnter Your Option (1): ";
	cin>>ch;
    cls();
	switch(ch)
	{
        case '1':	cout<<"\n\n\tenter student ID (without \"A\"): "; cin>>num;
					modify_offer(num); break;
		default:	cout<<"\a";
	}
}

void result4()				// Export Student List
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
	myfile << filemem << "\n\n";
	myfile << "HKU	BEng - Computer Science	HKU-CS	7	3.6	30 Dec 2013" << "\n";
	myfile << "HKU	BEng - Computer Engineering	HKU-CE	5	3.7	30 Dec 2013" << "\n";
	myfile << "HKUST	BSc - Computer Science	HKUST-CS	10	3.55	31 Oct 2013" << "\n";
	myfile << "HKUST	BEng - Computer Engineering	HKUST-CE	15	3.45	31 Oct 2013" << "\n";
	myfile << "PolyU	BSc in Computing	PolyU-COMP	20	3.35	28 Feb 2014" << "\n";
	myfile << "CityU	BEng in Information Engineering	CityU-IE	7	3.3	28 Feb 2014" << "\n";
	myfile << "CUHK	BSc in Computer Science	CUHK-CS	8	3.5	2 Jan 2014" << "\n";
	myfile << "CUHK	BEng in Computer Engineering	CUHK-CE	4	3.4	2 Jan 2014" << "\n";
	myfile << "HKBU	BSc in Computer Science	HKBU-CS	5	3.2	3 Jan 2013" << "\n";
	myfile.close();

	cout<<"\n\n\tExport Students Successfully";
	cin.get();
}
//***************************************************************
//    	Ivan Ivan Ivan Ivan Ivan Ivan Ivan Ivan Ivan Ivan Ivan
//****************************************************************

//***************************************************************
//    	Student Function , Student Function , Student Function
//****************************************************************
void class_result()		// Student Information 1
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
void display_all()			// Student Information 2
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
void display_sp(int n)		// Search Student
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
void write_student()		// Create Student Record, NOT USED
{
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}
void modify_student(int n)	// Modify Studnet Record, NOT USED
{
	bool found=false;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}

	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&st), sizeof(student));
		if(st.retrollno()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    int pos=(-1)*static_cast<int>(sizeof(st));
		    File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&st), sizeof(student));
		    cout<<"\n\n\t Record Updated";
		    found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();

}
void modify_student2(int n)	// Update GPA
{
	bool found=false;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}

	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&st), sizeof(student));
		if(st.retrollno()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata2();
		    int pos=(-1)*static_cast<int>(sizeof(st));
		    File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&st), sizeof(student));
		    cout<<"\n\n\tRecord Updated";
			st.showdata2();
		    found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\nRecord Not Found ";
	cin.ignore();
	cin.get();
}
void modify_offer(int n)		// Assign / Update Offer
{
	bool found=false;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}

	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&st), sizeof(student));
		if(st.retrollno()==n)
		{
			st.showoffer();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getoffer();
		    int pos=(-1)*static_cast<int>(sizeof(st));
		    File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&st), sizeof(student));
		    cout<<"\n\n\tRecord Updated";
			st.showoffer();
		    found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\nRecord Not Found ";
	cin.ignore();
	cin.get();
}
//***************************************************************
//    	Student Function , Student Function , Student Function
//****************************************************************

//***************************************************************
//    	Programme Function , Programme Function , Programme Function
//****************************************************************
void prog_result()			// Programme Information 1
{
	prog pg;
	ifstream inFile;
	inFile.open("prog.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\tProgramme Information \n\n";
	cout<<"===============================================================================\n";
	cout<<"Univ      Prog.Name        Prog.Code   Quota   Vacancy   Cutoff GPA."<<endl;
	cout<<"===============================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&pg), sizeof(prog)))
	{
		pg.show_tabular2();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}

void display_pall()		// Programme Information 2
{
	prog pg;
	ifstream inFile;
	inFile.open("prog.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tProgramme Information\n\n";
	while(inFile.read(reinterpret_cast<char *> (&pg), sizeof(prog)))
	{
		pg.showprog();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void write_prog()			// Create Programme Record, NOT USED
{
	prog pg;
	ofstream outFile;
	outFile.open("prog.dat",ios::binary|ios::app);
	pg.getprog();
	outFile.write(reinterpret_cast<char *> (&pg), sizeof(prog));
	outFile.close();
    cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}

void possible_prog(int n)	// Possible Programme
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
	  		 st.showdata3();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}
void prog_sp(int n)		// Search Programme
{
	prog pg;
	ifstream inFile;
	inFile.open("prog.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&pg), sizeof(prog)))
	{
		if(pg.retrollno2()==n)
		{
	  		 pg.showprog();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}
//***************************************************************
//    	Programme Function , Programme Function , Programme Function
//****************************************************************
