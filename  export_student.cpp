#include <iostream>
#include <fstream>
using namespace std;

void export_student() {
char filemem[50];
char filename[50];
cout<<"\n\n\n\t****** Export Student List ******";
cout<<"\n\n\tEnter Programme Code:";
cin.getline(filemem,50);
cout<<"\n\tEnter filename to export to:";
cin.getline(filename,50);

ofstream myfile;
myfile.open (filename);
myfile << filemem << "\n";

//$  string ProChoice;
//$  this->StudentData[Student.index].getProChoice(dProChoice);
//$  myfile<<ProChoice;

myfile.close();

cout<<"\n\n\tExport Students Successfully";
cin.get();
}



int main() {
export_student();
return 0;
}