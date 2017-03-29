#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "complex.cpp"
using namespace std;

int main() {
    fstream dataFile("126import.txt", ios::in);
    fstream outFile ("126export.txt", ios::out);
    string line;
    double realNum;
    double imagNum;
    int symbol;
    char ch;
    string line1;
    string line2;
    complex sum;
    complex *storage = new complex[100];
    int count = 0;
    
    dataFile >> line;
    while(dataFile)
    {
    char firstch = '+';
    ch = '+';
    if(line.length()==2)
    symbol = 3;
    else
    symbol=line.find("+");
    if(line.at(0) == '-')
    {
        line = line.substr(1,line.length() - 1);
        firstch = '-';
    }
    
    
    ch = '+';
    if(symbol < 0)
    {
        symbol = line.find("-");
        ch = '-';
    }
        stringstream stream(line);
        if(line.length()!=2)
        getline(stream, line1, ch);
        getline(stream, line2, 'i');
        line1=firstch+line1;
        realNum = atof(line1.c_str());
        imagNum = atof(line2.c_str());
        line2="0";
        line1="0";
        if(ch == '-')
            imagNum *= -1;
        else 
        {
        ch=='+';
        }
        if(isdigit(line1[0])|| line1[0]=='-')
        {
            complex ct(realNum, imagNum, ch);
            storage[count]=ct;
        }
        dataFile >> line; 
        count++;
    }
    sort(storage,count);
userChoice(storage,count,outFile,sum);

    return 0;
}

