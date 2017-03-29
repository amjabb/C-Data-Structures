//
//  portfolio.hpp
//  lab4
//
//  Created by Amir Jabbari on 9/20/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#ifndef portfolio_hpp
#define portfolio_hpp
#include <iostream>
#include "stock.hpp"

using namespace std;
class portfolio
{
public:
    portfolio();
    bool load(string);
    void print();
    void print_rev();
    bool save(string="");
    bool remove(string);
    void add(string,int);
    void addToBeg(string,int);
    void addToMid(string,int);
    void recPrint_rev(stockNode* );
    void userChoice();
    
private:
    stockNode * head;
    stockNode * tail;
    string dbFileName;
};

#endif /* portfolio_hpp */
