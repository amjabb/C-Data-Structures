#include <iostream>
using namespace std;
#include "stock.h"
stock::stock()
{
    sname = "";
    sprice = 0;
}
stock::stock(string n, int p)
{
    sname = n;
    sprice = p;
}
ostream& operator<<(ostream& os, const stock& s)
{
    os << "Stock name: " << s.sname << " Stock price: " << s.sprice << endl;
    return os;
}