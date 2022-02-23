#include "fileprocessor.h"
#include "translator.h"
#include <iostream>
#include <fstream>
using namespace std;

//Nothing is being stored here, so left blank


fileprocessor::fileprocessor(){
  //nothing
}

//Nothing is being destructed here, so left blank


fileprocessor::~fileprocessor(){
  //nothing
}

/*
processFile is a method in the fileprocessor class.
It receives a name of the input file as string, and the name of output file as a string
It is type void because we are not returning anything.
It opens a file with ifstream, writes the contents down in a string stored here.
Then the output file is created or opened, and the string is passed into it.
It gets written in the new file, then closes.
*/

void fileprocessor::processFile(string input_file, string output_file){
  ifstream in_file;
  translator *finisher;
  string line;
  string line1;
  in_file.open(input_file);
  //int y = 0;

    while(getline(in_file,line)){
      line1 = line1 + finisher->translateEnglishSentence(line) + "\n";
  //    y++;
}
    in_file.close();

    ofstream out_file;
    out_file.open(output_file);
    out_file << line1 << endl;
    out_file.close();
}

/*
processTut takes an inputfile and outputfile and acts the exact same as processFile,
but instead uses translateTutSentence instead of translateEnglishSentence.
This is the method used for translating an Tutnese Input text file to and English output text file.
*/


void fileprocessor::processTut(string input_file1, string output_file1){
  ifstream in_file1;
  translator *finisher2;
  string line_A;
  string line2;
  in_file1.open(input_file1);

    while(getline(in_file1,line_A)){
      line2 = line2 + finisher2->translateTutSentence(line_A) + "\n";
}
    in_file1.close();

    ofstream out_file1;
    out_file1.open(output_file1);
    out_file1 << line2 << endl;
    out_file1.close();

}
