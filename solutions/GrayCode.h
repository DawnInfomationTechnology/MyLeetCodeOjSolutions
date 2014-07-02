//
//  GrayCode.h
//  MyLeetCodeOjSolutions
//
//  Created by zhangxu on 3/7/14.
//  Copyright (c) 2014 zhangxu. All rights reserved.
//

#ifndef MyLeetCodeOjSolutions_GrayCode_h
#define MyLeetCodeOjSolutions_GrayCode_h

// reflect-and-prefix method.
// code[n] = { code[n-1][1], code[n-1][2], ..., code[n-1][m],
//            (1<<n)|code[n-1][m], ..., (1<<n)|code[n-1][1]}

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result;
        result.push_back(0);
        
        if( n <= 0) return result;
        
        // init for n = 1
        int codeCount = 2;
        result.push_back(1);
        
        int reflectMask = 1 << 1;
        for( int i = 1; i < n; ++i)
        {
            for( int j = 1; j <= codeCount; ++j)
            {
                result.push_back( reflectMask | result[ codeCount-j]);
            }
            
            codeCount *= 2;
            reflectMask = reflectMask << 1;
        }
        
        return result;
    }
};


#endif
