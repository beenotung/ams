/*
 * AMS v0.1 testing
 */
//menu start
//menu content
//menu end
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

int main()
{
   welcome();

   cout<<man_string("\n",2);

   ///loadfromfile();


   leave();
   cout<<center("normal end");
   char c;
   cin>>c;
}

