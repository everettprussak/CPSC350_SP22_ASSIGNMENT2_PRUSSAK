#include "model.h"
#include <iostream>
using namespace std;

//Nothing is being stored here, so left blank

model::model(){
  //nothing
}

//Nothing is being destructed here, so left blank

model::~model(){
  //nothing
}

/*
translateSingleCharacter takes a single char, and converts into Tutnese.
It uses a number of if statements and for loops to get the correct conversion
rather that be upper case, lower case, which letter, or an unknown symbol.
*/

string model::translateSingleCharacter(char a){
   bool case_a = isupper(a);
   char other = tolower(a);
   string ret;
   if(other=='b'){
     ret = "bub";
   }
   else if(other=='c'){
     ret = "cash";
   }
   else if(other=='d'){
     ret = "dud";
   }
   else if(other=='f'){
     ret = "fuf";
   }
   else if(other=='g'){
     ret = "gug";
   }
   else if(other=='h'){
     ret = "hash";
   }
   else if(other=='j'){
     ret = "jay";
   }
   else if(other=='k'){
     ret = "kuck";
   }
   else if(other=='l'){
     ret = "lul";
   }
   else if(other=='m'){
     ret = "mum";
   }
   else if(other=='n'){
     ret = "nun";
   }
   else if(other=='p'){
     ret = "pub";
   }
   else if(other=='q'){
     ret = "quack";
   }
   else if(other=='r'){
     ret = "rug";
   }
   else if(other=='s'){
     ret = "sus";
   }
   else if(other=='t'){
     ret = "tut";
   }
   else if(other=='v'){
     ret = "vuv";
   }
   else if(other=='w'){
     ret = "wack";
   }
   else if(other=='x'){
     ret = "ex";
   }
   else if(other=='y'){
     ret = "yub";
   }
   else if(other=='z'){
     ret = "zub";
   }

   else{
     string punct;
     punct = punct + a;
     return punct;
   }

   if(case_a==true){
     string upper_return;
     for(int i=0; i<ret.length(); ++i){
       if(i==0){
         char t = toupper(ret[0]);
         upper_return = upper_return + t;
         continue;
       }
       upper_return = upper_return + ret[i];
     }
     return upper_return;
   }
   return ret;
}

/*
translateDoubleCharacter is a method in the model class.
It takes a single char as input, and converts it into the correct
Tutnese translation. There are a number of if statements to correctly
identify the letter, symbol, or other.
It then returns the correct Tutnese translation in the form of a string
*/

string model::translateDoubleCharacter(char b){
    bool case_b = isupper(b);
    char other = tolower(b);
    string ret;

    if(other=='a'||other=='e'||other=='o'||other=='u'||other=='i'){
      if(case_b==true){
        ret = "Squat";
        ret = ret + other;
        return ret;
      }
      ret = "squat";
      ret = ret + other;
      return ret;
    }
    else{
      if(case_b==true){
        ret = "Squa" + translateSingleCharacter(b);
        return ret;
      }
      else{
        ret = "squa" + translateSingleCharacter(b);
      }
    }
    return ret;
}

/*
translateTutCharacter is a method in the model class.
It gets a string inputed, and checks to see if the string
equals any of the equivlent english letter to tutnese trasnlation is.
If the string is a tutnese letter, then the English letter is returned.
It also plays a role in checking for double letters from tutnese.
If "squa" is the string, then it will be a double letter, and will return
"double" to let the other method/class know what is going on here. It also checks
for non-alphabet characters, such as "!", "?", ".", etc.
*/

string model::translateTutCharacter(string c1){
  bool case_c = isupper(c1[0]);
  string c;
  for(char t: c1){
    char h = tolower(t);
    c = c + h;
  }

  if(c=="bub"){
    if(case_c==true){
      return "B";
    }
    else{
      return "b";
    }
  }

  else if(c=="cash"||c=="squacash"){
    if(case_c==true){
      return "C";
    }
    else{
      return "c";
    }
  }

  else if(c=="dud"){
    if(case_c==true){
      return "D";
    }
    else{
      return "d";
    }
  }

  else if(c=="fuf"){
    if(case_c==true){
      return "F";
    }
    else{
      return "f";
    }
  }

  else if(c=="gug"){
    if(case_c==true){
      return "G";
    }
    else{
      return "g";
    }
  }

  else if(c=="hash"){
    if(case_c==true){
      return "H";
    }
    else{
      return "h";
    }
  }

  else if(c=="jay"){
    if(case_c==true){
      return "J";
    }
    else{
      return "j";
    }
  }

  else if(c=="kuck"){
    if(case_c==true){
      return "K";
    }
    else{
      return "k";
    }
  }

  else if(c=="lul"){
    if(case_c==true){
      return "L";
    }
    else{
      return "l";
    }
  }

  else if(c=="mum"){
    if(case_c==true){
      return "M";
    }
    else{
      return "m";
    }
  }

  else if(c=="nun"){
    if(case_c==true){
      return "N";
    }
    else{
      return "n";
    }
  }

  else if(c=="pub"){
    if(case_c==true){
      return "P";
    }
    else{
      return "p";
    }
  }

  else if(c=="quack"){
    if(case_c==true){
      return "Q";
    }
    else{
      return "q";
    }
  }

  else if(c=="rug"){
    if(case_c==true){
      return "R";
    }
    else{
      return "r";
    }
  }

  else if(c=="sus"){
    if(case_c==true){
      return "S";
    }
    else{
      return "s";
    }
  }

  else if(c=="tut"){
    if(case_c==true){
      return "T";
    }
    else{
      return "t";
    }
  }

  else if(c=="vuv"){
    if(case_c==true){
      return "V";
    }
    else{
      return "v";
    }
  }

  else if(c=="wack"){
    if(case_c==true){
      return "W";
    }
    else{
      return "w";
    }
  }

  else if(c=="ex"){
    if(case_c==true){
      return "X";
    }
    else{
      return "x";
    }
  }

  else if(c=="yub"){
    if(case_c==true){
      return "Y";
    }
    else{
      return "y";
    }
  }

  else if(c=="zub"){
    if(case_c==true){
      return "Z";
    }
    else{
      return "z";
    }
  }

  else if(c=="a"||c=="e"||c=="i"||c=="o"||c=="u"){
    return c1;
  }

  else if(c=="squa"){
    if(case_c==true){
      return "Double";
    }
    return "double";
  }

  for(int y=0; y<c.length(); ++y){
    if(isalpha(c[y])){
      continue;
    }
    else{
      return c1;
    }
  }

  return "NonExisting";
}
