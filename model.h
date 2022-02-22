#include <iostream>
using namespace std;

/*
Simple header class for the model class.
*/

class model{
public:
    model();
    ~model();
    string translateSingleCharacter(char a);
    string translateDoubleCharacter(char b);
    string translateTutCharacter(string c);
};
