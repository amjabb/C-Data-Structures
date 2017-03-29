//
//  main.cpp
//  stlEval
//
//  Created by Amir Jabbari on 10/27/15.
//  Copyright © 2015 Amir Jabbari. All rights reserved.
//


#include "infixToPostFix.h"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    infixToPostfix a("A+B-C");
    a.showInfix();
    a.showPostfix();
    infixToPostfix b("(A+B)*C");
    b.showInfix();
    b.showPostfix();
    infixToPostfix c("(A+B)*(C-D)");
    c.showInfix();
    c.showPostfix();
    infixToPostfix d("A+((B+C)*(E-F)-G)/(H-I)");
    d.showInfix();
    d.showPostfix();
    infixToPostfix e("A+B*(C+D)-E/F*G+H");
    e.showInfix();
    e.showPostfix();
    
    infixToPostfix f("8+7-6");
    f.showInfix();
    f.showPostfix();
    f.eval();
    infixToPostfix g("(8+7)*6");
    g.showInfix();
    g.showPostfix();
    g.eval();
    infixToPostfix h("(8+7)*(6-5)");
    h.showInfix();
    h.showPostfix();
    h.eval();
    infixToPostfix i("8+((7+6)*(4-3)-2)/(1-0)");
    i.showInfix();
    i.showPostfix();
    i.eval();
    infixToPostfix j("8+7*(6+5)-4/3*2+1");
    j.showInfix();
    j.showPostfix();
    j.eval();
    
}
