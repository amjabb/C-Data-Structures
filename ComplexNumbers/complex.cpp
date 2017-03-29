#include "complex.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h> 
using namespace std;

complex::complex()
{
    real = 0;
    imag = 0;
    sign = '+';
}
complex::complex(double r, double i,char signin)
{
    if(r!=0)
    real = r;
    else 
    real = 0;
    if(i!=0)
    imag = i;
    else
    imag = 0;
    sign=signin;
}


complex complex::operator + (const complex& c1)
{
    complex c2;
    c2.real = real + c1.real;
    c2.imag = imag + c1.imag;
    return c2;
}

ostream& operator<<(ostream& os, const complex& c1)
{
    os << c1.real << "+" << "("<<c1.imag << "i"<<")";
    return os;
}
complex complex::operator=(const complex& c1)
{
    if(this!=&c1)
    {
        real = c1.real;
        imag = c1.imag;
    }
}
double complex::getReal() const
{
    return real;
}
double complex::getImag() const
{
    return imag;
}

void list(complex c1[], int count)
{
    for(int i=0;i<count;i++)
    {
        cout << c1[i] <<endl;
    }
}
void save(complex c1[], int count,fstream& f1)
{
    for(int i=0;i<count;i++)
    {
        f1 << c1[i] << endl;
    }
    f1<<"\n";
}
void add(complex c1[],int count,complex cAdd)
{
    for (int i = count; i>0; i--)
        c1[i] = c1[i-1];
        
        c1[0] = cAdd;
        
        count++;
}
void csum(complex c1[],int count,fstream& f1)
{
    complex sum;
    for(int i = 0; i<count;i++)
    {
         sum = sum + c1[i]; 
    }
    f1 << "Sum: "<<sum<<"\n";
    cout << "Sum: "<<sum<<"\n";
}
void cdelete(complex c1[],int count)
{
    for(int i = 0; i<count-1;i++)
    {
        c1[i] = c1[i+1];
    }
    count--;
}
void sort(complex c1[], int count)
{
    complex temp;
    count--;
    for(int i =0;i<count;i++)
    {
        for(int j = 0; j<count-i;j++)
        {
            if((sqrt((c1[j].getReal() * c1[j].getReal())+(c1[j].getImag() * c1[j].getImag()))) 
                > (sqrt((c1[j+1].getReal() * c1[j+1].getReal())+(c1[j+1].getImag() * c1[j+1].getImag()))))
            {
                temp=c1[j];
                c1[j]=c1[j+1];
                c1[j+1] = temp; 
            }
        }
    }
}
void userChoice(complex storage[],int count,fstream& outFile,complex sum)
{
        int choice;
bool gameOn = true;
while (gameOn != false){
cout << "*******************************\n";
cout << " 1 - Add\n";
cout << " 2 - Delete the first one\n";
cout << " 3 - List to Screen\n";
cout << " 4 - Save to File\n";
cout << " 5 - Sum\n";
cout << " 6 - Exit Program\n";
cout << " Enter your choice and press return: ";

cin >> choice;

switch (choice)
{
case 1:
{
double real,imag;
cout<<"Enter the real part:";
cin>>real;
cout<<"Enter the imaginary part:";
cin>>imag;
char ch = '+';
complex cn(real,imag,ch);
add(storage,count,cn);
}
break;
case 2:
cdelete(storage,count);
break;
case 3:
sort(storage,count);
list(storage,count);
break;
case 4:
{
sort(storage,count);
save(storage,count,outFile);
}
break;
case 5:
csum(storage,count,outFile);
break;
case 6:
cout << "End of Program.\n";
gameOn = false;
break;
default:
cout << "Not a Valid Choice. \n";
cout << "Choose again.\n";
cin >> choice;
break;
}

}
}