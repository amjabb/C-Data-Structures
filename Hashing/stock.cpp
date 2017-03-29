//
//  stock.cpp
//  search
//
//  Created by Amir Jabbari on 10/29/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include "stock.hpp"
#include <iostream>
using namespace std;
stock::stock()
{
    sname = "empty";
    sprice = 0;
}
stock::stock(string n, int p)
{
    sname = n;
    sprice = p;
}
void stock::stockInit(string n, int p)
{
    sname = n;
    sprice = p;
}
ostream& operator<<(ostream& os, const stock& s)
{
    os << "Stock name: " << s.sname << " Stock price: " << s.sprice << endl;
    return os;
}

int stock::getPrice(){
    return sprice;
}

string stock::getName(){
    return sname;
}

void stock::setName(string name){
    sname = name;
}

void stock::setPrice(int price){
    sprice = price;
}