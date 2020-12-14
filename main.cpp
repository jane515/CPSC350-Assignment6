//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 5
#include "Process.h"
int main(int argc, char const *argv[]) {
  //check if there is any input from command line
  if(argc<2)
  {
    cout << "You need to Enter an argument"<<endl;
    return -1;
  }
  else if(argc>3)
  {
    cout<<"You are only allowed to enter one file name"<<endl;
    return -1;
  }
  Process p;
  string file = argv[1];
  p.run(file);
  return 0;
}
