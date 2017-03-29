//
//  palindrome.cpp
//  queue
//
//  Created by Amir Jabbari on 11/5/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//

#include "palindrome.hpp"
#include <iostream>
#include <string>
using namespace std;

Palindrome::Palindrome(string input){
    char* forwards = new char[input.length()];
    char* backwards = new char[input.length()];
    int size = 0;
    Queue queue(input.length());
    Queue queue2(input.length());
    bool same = true;
    for(int i = 0; i < input.length(); i++)
    {
        if (isalpha(input[i])){
        queue.enQueue(input[i]);
            size++;
        }
    }
    int j = 0;
    for(int i = input.length()-1; i >= 0 ; i--)
    {
        if (isalpha(input[i])) {
        backwards[j] = input[i];
        j++;
        }
    }
    for(int i = 0; i < size; i++)
    {
        queue2.enQueue(backwards[i]);
    }
    for(int i = 0; i < size; i++)
    {
        if(tolower(queue.deQueue()) == tolower(queue2.deQueue())){
            same = true;
        }
        else
        {
            same = false;
            cout << input << " is not a palindrome" << endl;
            return;
        }
    }
    cout << input << " is a palindrome!!" << endl;
    
}
