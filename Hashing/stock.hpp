//
//  stock.hpp
//  search
//
//  Created by Amir Jabbari on 10/29/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#ifndef stock_hpp
#define stock_hpp

#include <iostream>
using namespace std;

class stock
{
    string sname;
    int sprice;
public:
    stock();
    stock(string,int);
    void stockInit(string="empty",int=0);
    int getPrice();
    void setName(string);
    void setPrice(int);
    string getName();
    friend ostream& operator<<(ostream&, const stock&);
};
#endif /* stock_hpp */
