//
//  Triangle.h
//  MyLeetCodeOjSolutions
//
//  Created by zhangxu on 1/7/14.
//  Copyright (c) 2014 zhangxu. All rights reserved.
//

#ifndef MyLeetCodeOjSolutions_Triangle_h
#define MyLeetCodeOjSolutions_Triangle_h

// dp[i][j] = t[i][j] + MIN{ t[i+1][j], t[i+1][j+1]}

class Solution
{
#define MIN(l,r) ((l)<(r)?(l):(r))

public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        const int rowCount = triangle.size();
        int dp[rowCount]; // rowCount == triangle[rowCount-1].size()
        
        // init dp
        for( int i = 0; i < rowCount; ++i)
            dp[i] = triangle[rowCount-1][i];
        
        // do dp
        for( int i = rowCount -2; i >= 0; --i)
        {
            for( int j = 0; j <= i; ++j)
                dp[j] = triangle[i][j] + MIN( dp[j], dp[j+1]);
        }
        
        return dp[0];
    }
};


#endif
