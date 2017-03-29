//
//  queue.cpp
//  queue
//
//  Created by Amir Jabbari on 11/5/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include "queue.hpp"
#include <iostream>

using namespace std;

Queue::Queue(int max){
    size = max;
    top = 0;
    list = new char[max];
}

Queue::~Queue(){
    delete list;
}

void Queue::enQueue(char item){
    list[top++]=item;
}

char Queue::deQueue(){
    return list[--top];
}
