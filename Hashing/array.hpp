//
//  array.hpp
//  search
//
//  Created by Amir Jabbari on 10/29/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#ifndef array_hpp
#define array_hpp
#include "stock.hpp"
#include <iostream>
using namespace std;

class Array{
public:
    Array();
    Array(int);
    void initializeArray(int count);
    void printArray();
    int getLength();
    void seqSearch(int);
    int seqRecSearch(int,int);
    void setseqRecSearch(int);
    void binSearch(int);
    int binRecSearch(int,int,int);
    void setbinRecSearch(int);
    void sort();
private:
    stock *list;
    int length;
};

#endif /* array_hpp */
