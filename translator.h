#include <iostream>
using namespace std;

/*
Simple header class for the translator class.
*/

class translator{
public:
    translator();
    ~translator();
    string translateEnglishWord(string a);
    string translateEnglishSentence(string b);
    string translateTutWord(string c);
    string translateTutSentence(string d);
};
