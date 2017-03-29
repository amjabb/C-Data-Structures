#include <iostream>
using namespace std;

class stock
{
    string sname;
    int sprice;
    public:
    stock();
    stock(string,int);
    friend ostream& operator<<(ostream&, const stock&);
};