//
//  stock.cpp
//  lab4
//
//  Created by Amir Jabbari on 9/20/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include "stock.hpp"
#include <iostream>
using namespace std;

stock::stock()
{
    sname = "";
    sprice = 0;
}
stock::stock(string n, int p)
{
    n = sname;
    p = sprice;
}

stock stock::operator=(stock& s)
{
    this->sname = s.sname;
    this->sprice = s.sprice;
    return *this;
}


ostream& operator<<(ostream& os, const stock& s)
{
    os << "Stock name: " << s.sname << " Stock price: " << s.sprice << endl;
    return os;
}

istream& operator>>(istream& is, stock& s)
{
    is >> s.sname >> s.sprice;
    return is;
}