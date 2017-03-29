//
//  stackArray.hpp
//  stackArray
//
//  Created by Amir Jabbari on 10/27/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#ifndef stackArray_hpp
#define stackArray_hpp

#include <iostream>
using namespace std;
class stackArray{
public:
    stackArray(int = 100);
    ~stackArray();
    void push(char);
    char pop();
    char getTop();
    bool isEmptyStack();
    bool isFullStack();
private:
    int size;
    int top;
    double *list;
};
#endif /* stackArray_hpp */
