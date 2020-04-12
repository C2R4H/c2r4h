#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;

bool isempty(){
  ifstream pFile;
  pFile.open("data.txt");
  bool isempty(true);
  string line;
  while(pFile>>line){
    isempty = false;
  }
  return isempty;
}

void start(){
  if(isempty()){
    ofstream out;
    out.open("data.txt");
    string name;
    cout<<endl;
    cout<<"     Name of the file : ";cin>>name;
    out<<name<<endl;
  }
}
void back(){
  char c;
  cin>>c;
  if(c!='q'){
    cin>>c;
  }
}

int menu(){
  system("clear");int n;
  cout<<endl;
  cout<<"     1--->Compile"<<endl;
  cout<<"     2--->Type"<<endl;
  cout<<"     3--->Reset"<<endl;
  cout<<"     4--->Remove"<<endl<<endl;
  cout<<"   Insert :";cin>>n;return n;
}
void comp(){
  system("clear");
  ifstream in;
  in.open("data.txt");
  string name;string pname;
  while(in>>pname){
    name = pname;
  }
  //const char* c = name.c_str();
  string out = "g++ ";
  string namep = name;namep.append(".cpp");
  string namee = name;namee.append(".exe");
  out.append(namep);out.append(" -o ");
  out.append(namee);
  const char* c = out.c_str();
  system(c);
  string exec = "./";
  exec.append(namee);
  const char* ex = exec.c_str();
  system(ex);in.close();
}
void remove(){
  system("clear");
  cout<<endl;
  system("ls");
  cout<<"     ";
  string nume;
  cout<<endl;
  cout<<"   Introduceti : ";cin>>nume;
  string out = "rm ";
  out.append(nume);
  const char* ex = out.c_str();
  system(ex);
}
void type(){
  system("clear");
  ifstream in;
  in.open("data.txt");
  string name;string pname;
  while(in>>pname){
    name = pname;
  }string out = "vi ";
  out.append(name);
  out.append(".cpp");
  const char* c = out.c_str();
  system(c);
}
int main(){
  while(true){
    start();
    int nr = menu();
    if(nr == 1){comp();back();}
    if(nr == 2){type();}
    if(nr == 3){system("rm data.txt");}
    if(nr == 4){remove();}
  }
}
