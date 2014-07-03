//
//  EvaluateReversePolishNotation.h
//  MyLeetCodeOjSolutions
//
//  Created by zhangxu on 3/7/14.
//  Copyright (c) 2014 zhangxu. All rights reserved.
//

#ifndef MyLeetCodeOjSolutions_EvaluateReversePolishNotation_h
#define MyLeetCodeOjSolutions_EvaluateReversePolishNotation_h

class Solution
{
public:
    template<typename T>
    T toNum( string s)
    {
        T r;
        stringstream ss;
        ss << s;
        ss >> r;
        return r;
    }
    
    template<typename T>
    T calculate( T n1, T n2, string op)
    {
        if( op == "+") return n1+n2;
        else if( op == "-") return n1-n2;
        else if( op == "*") return n1*n2;
        else if( op == "/") return n1/n2;
        else return (T)0;
    }
    
    
    bool isOperator( string s)
    {
        return (s=="*")|(s=="/")|(s=="+")|(s=="-");
    }
    
    int evalRPN(vector<string> &tokens)
    {
        std::stack<int> numStack;
        if( tokens.empty()) return 0;
        
        int n1, n2;
        for( int i = 0; i < tokens.size(); ++i)
        {
            if( isOperator(tokens[i]))
            {
                n1 = numStack.top(); numStack.pop();
                n2 = numStack.top(); numStack.pop();
                numStack.push( calculate<int>(n2,n1,tokens[i]));
            }
            else
            {
                numStack.push(toNum<int>(tokens[i]));
            }
        }
        
        return numStack.top();
    }
};


#endif
