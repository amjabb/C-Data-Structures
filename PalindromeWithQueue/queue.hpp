//
//  queue.hpp
//  queue
//
//  Created by Amir Jabbari on 11/5/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <iostream>

using namespace std;

class Queue {
public:
    Queue(int);
    ~Queue();
    void enQueue(char);
    char deQueue();
private:
    int size;
    int top;
    char *list;
};

#endif /* queue_hpp */
