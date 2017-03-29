//
//  stock.hpp
//  lab4
//
//  Created by Amir Jabbari on 9/20/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#ifndef stock_hpp
#define stock_hpp

#include <iostream>
using namespace std;

class stock
{
public:
    string sname;
    int sprice;
    
    stock();
    stock(string,int);
    stock operator=(stock&);
    friend ostream& operator<<(ostream&, const stock&);
    friend istream& operator>>(istream&, stock&);
};
//stockNode with inheritance
//the memory of the stock class is created but obviously
//there is no code other than the pointers 
class stockNode : public stock //stockNode is a stock
{
public:
    stockNode *next;
    stockNode *back;
};

#endif /* stock_hpp */
