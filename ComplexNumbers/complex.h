#include <iostream>
using namespace std;

class complex
{
    double real, imag;
    char sign;
    public:
    double absolute;
    complex();
    complex(double, double,char);
    complex operator + (const complex&);
    complex operator=(const complex&);
    void save (complex[],int,fstream&);
    void add(complex[],int,complex);
    friend ostream& operator<<(ostream&, const complex&);
    double getReal() const;
    double getImag() const;
    void cdelete(complex[],int);
    void list(complex[], int);
    void csum(complex[],int,fstream&);
    void sort(complex [],int);
    void userChoice(complex storage[],int* ,fstream& outFile,complex);
};