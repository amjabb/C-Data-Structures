//
//  stackArray.cpp
//  stackArray
//
//  Created by Amir Jabbari on 10/27/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include "stackArray.hpp"

#include <iostream>
using namespace std;

stackArray::stackArray(int max){
    size = max;
    top = 0;
    list = new double[max];
}

stackArray::~stackArray(){
    delete list;
}

void stackArray::push(char item){
    list[top++]=item;
}

char stackArray::pop(){
    return list[--top];
}
char stackArray::getTop(){
    return list[top-1];
}

bool stackArray::isEmptyStack(){
    return (top == 0);
}

bool stackArray::isFullStack(){
    return top == size;
}