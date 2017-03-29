//Implementation File

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include "infixToPostfix.h"

using namespace std;

void infixToPostfix::convertToPostfix()
{
    char stackOpr;
    
    pfx = "";
    int len = ifx.length();
    
    for (int i = 0; i < len; i++)
        if (isdigit(ifx[i]) || ifx[i] == '.' || (ifx[i] >= 'A' && ifx[i] <= 'Z'))
            pfx = pfx + ifx[i];
        else
        {
            switch (ifx[i])
            {
                case '(':
                    stack.push(ifx[i]);
                    break;
                    
                case ')':
                    stackOpr = stack.getTop();
                    stack.pop();
                    
                    while (stackOpr != '(')
                    {
                        pfx = pfx + stackOpr;
                        
                        if (!stack.isEmptyStack())
                        {
                            stackOpr = stack.getTop();
                            stack.pop();
                        }
                        else
                            break;
                    }
                    break;
                    
                case ';':
                case ' ':
                    break;
                    
                default:
                    if (stack.isEmptyStack())
                        stack.push(ifx[i]);
                    else
                    {
                        stackOpr = stack.getTop();
                        stack.pop();
                        
                        while (precedence(stackOpr,ifx[i]))
                        {
                            pfx = pfx + stackOpr;
                            if (!stack.isEmptyStack())
                            {
                                stackOpr = stack.getTop();
                                stack.pop();
                            }
                            else
                                break;
                        }
                        
                        if (!precedence(stackOpr,ifx[i]))
                            stack.push(stackOpr);
                        
                        stack.push(ifx[i]);
                    }
                    
            }
        }
    
    while (!stack.isEmptyStack())
    {
        pfx += stack.getTop();
        stack.pop();
    }
    
}


bool infixToPostfix::precedence(char opr1, char opr2)
{
    int prec1, prec2;
    
    if (opr1 == '*' || opr1 =='/')
        prec1 = 2;
    else if(opr1 == '+' || opr1 == '-')
        prec1 = 1;
    else if(opr1 =='(')
        prec1 = 0;
    
    if (opr2 == '*' || opr2 == '/')
        prec2 = 2;
    else if(opr2 =='+' || opr2 == '-')
        prec2 = 1;
    
    return(prec1 >= prec2);
}//end precedence

void infixToPostfix::getInfix(string data)
{
    ifx = data;
    convertToPostfix();
}

void infixToPostfix::showInfix()
{
    cout << "\nInfix: " << ifx << endl;
}


void infixToPostfix::showPostfix()
{
    cout << "Postfix: " << pfx;
}

infixToPostfix::infixToPostfix(string infx)
{
    ifx = infx;
    convertToPostfix();
}

void infixToPostfix::eval(){
    int size = pfx.length();
    stackArray s;
    int i = 0;
    char ch;
    int val = 0;
    int op1 = 0;
    int op2 = 0;
    while (i < size) {
        ch = pfx[i];
        if (isdigit(ch) || ch == '.') {
            if ( ch == '.')
            {
                string str = "";
                str += pfx[i-1];
                str += pfx[i];
                str += pfx[i+1];
                s.push(stoi(str));
            }
            else
            s.push(ch-'0');
        }
        else {
            if(pfx[i+2] == '.'){
                op2 = s.getTop();
                s.pop();
                switch (ch) {
                    case '*': val = op2; break;
                    case '/': val = op2; break;
                    case '+': val = op2; break;
                    case '-': val = op2; break;
                    default : val = 0;
                }
                        }
            else{
                
                op1 = s.getTop();
                s.pop();
             op2 = s.getTop();
                s.pop();
            switch (ch) {
                case '*': val = op2 * op1; break;
                case '/': val = op2 / op1; break;
                case '+': val = op2 + op1; break;
                case '-': val = op2 - op1; break;
                default : val = 0;
            } }
            s.push(val);
        }
        i++;
    }
    cout << " = " << val << endl;
}



