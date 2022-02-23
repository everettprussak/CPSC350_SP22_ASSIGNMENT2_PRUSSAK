#include "translator.h"
#include "model.h"
#include <iostream>
using namespace std;

//Nothing needs to be stored in this instance for this class.
translator::translator(){
  //nothing
}

//Nothing needs to be destructed in this instance for this class.

translator::~translator(){
  //nothing
}

/*translateEnglishWord is a method in the translator class.
It takes a simple string as input, and then creates and instance of the model class.
Using the translateDoubleCharacter and translateSingleCharacter methods in the model class,
it will get the correct Tutnese translated word from the English word parameter.
*/

string translator::translateEnglishWord(string a){
  string ret;
  char temp;
  int counter = 0;
  model ab;
  for(char i: a){
    if(i==temp){
      string sing = ab.translateSingleCharacter(i);
      int sing_value = sing.length();
      ret.erase(counter-sing_value,sing_value);
      string doub = ab.translateDoubleCharacter(i);
      ret = ret + doub;
      counter = counter - sing_value;
      counter = counter + doub.length();
    }
    else{
      string word = ab.translateSingleCharacter(i);
      ret = ret + word;
      counter = counter + word.length();
    }
    temp = i;
  }
  return ret;
}

/*translateEnglishSentence is a method in the translator class.
Simple to the translateEnglishWord method, but instead takes longer input string.
It will check for spaces, and add characters into a string to make a word.
That word will then be used with the method translateEnglishWord() from above.
With all the words in the sentence being stored in the "ret" string,
it will be a fully tutnese translated string sentence that will be returned.
*/

string translator::translateEnglishSentence(string b){
  string ret = "";
  string word;
  int count = 0;
  for(char space: b){
    if(space==' '){
      ret = ret + translateEnglishWord(word) + " ";
      count = count + 1;
      word = "";
      continue;
    }
    word = word + space;
    count = count + 1;
    if(count==b.length()){
      ret = ret + translateEnglishWord(word);
    }
  }
  return ret;
}

/*
translateTutWord is a method in the translator class.
It takes a string as input from translateTutSentence, and then calls
a method from the model class (translateTutCharacter) to get an english word from
the inputed tutnese word.
It goes through a number of if statements to check for specific sequences of the
characters. Many times "NonExisting" will be the if statement it goes through
because that sequence of letters was not a specific sequence in tutnese. It also
goes through many if statements to check for double letters in tutnese. This is done With
checking if "double" is returned from translateTutCharacter, and what characters are coming
after. If there is a double letter ("squa") will be disregarded, then it will translate the
next tut string into an english character and be given to ret (our return string) twice to
simulate a double letter.
*/

string translator::translateTutWord(string c){
  string ret = "";
  char doubleletter;
  string temp = "";
  model cd;
  int double_counter = 0;
  bool capital = false;
  for(int i=0; i<c.length(); ++i){
    temp = temp + c[i];
    string af = cd.translateTutCharacter(temp);

    if((double_counter==1) && (temp=="t")){
      if(c[i+2]=='t'||c[i+2]=='T'){
        temp="t";
        continue;
      }
      temp = "";
      double_counter = 2;
      continue;
    }
    if(af=="NonExisting"){
      continue;
    }
    if(af=="double"||af=="Double"){
      temp = "";
      if(af=="Double"){
        capital = true;
      }
      double_counter = 1;
      continue;
    }
    if(double_counter==1){
      if(capital){
        char cap;
        cap = toupper(af[0]);
        af[0] = cap;
        ret = ret + af;
        cap = tolower(af[0]);
        af[0] = cap;
        ret = ret + af;
        temp = "";
        double_counter = 0;
        capital = false;
        continue;
      }
      ret = ret + af;
      ret = ret + af;
      temp = "";
      double_counter = 0;
      continue;
    }
    if(double_counter==2){
      ret = ret + af + af;
      temp = "";
      double_counter = 0;
      continue;
    }
    ret = ret + af;
    temp = "";
  }
  return ret;
}


/*
translateTutSentence is a method in the translator class.
It simply gets a long string from the fileProcessor class, and
calls the translateTutWord from the same translator class everytime there is
a space or newline. It collects all of the tranlated Tutnese words, into english,
then is returned as a full string of English Words which was inputed as Tutnese words.
*/


string translator::translateTutSentence(string d){
  string ret = "";
  string word;
  int count = 0;
  for(char space: d){
    if(space==' '){
      ret = ret + translateTutWord(word) + " ";
      count = count + 1;
      word = "";
      continue;
    }
    word = word + space;
    count = count + 1;
    if(count==d.length()){
      ret = ret + translateTutWord(word);
    }
  }
  return ret;
}
