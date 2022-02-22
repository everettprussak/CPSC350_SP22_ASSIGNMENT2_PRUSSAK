//Everett Prussak
//2368093
//2/11/2022
//CPSC 350 - 01
/*
The combination of main.cpp, model.h, model.cpp, translator.cpp, translator.h,
fileprocessor.h, and fileprocessor.cpp accepts a english worded file, and
creates a file translated into Tutnese.
*/


#include "model.h"
#include "translator.h"
#include "fileprocessor.h"
#include <iostream>



using namespace std;

//Main method:
//Three comand line arguements are given after ./assignment1.o
//first will be the input.txt, then the ouptut.txt and then Tut to English or English to Tut (E2T ot T2E)
//It will open up specific fileprocessor method

int main(int argc, char **argv){

  fileprocessor f1;

  string conversion = argv[3];
  if(conversion=="E2T"){
    f1.processFile(argv[1],argv[2]);
  }
  else if(conversion=="T2E"){
    f1.processTut(argv[1],argv[2]);
  }
  else{
    cout << "Type E2T or T2E" << endl;
  }

  return 0;
}
