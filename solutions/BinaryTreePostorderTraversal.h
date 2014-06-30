//
//  BinaryTreePostorderTraversal.h
//  MyLeetCodeOjSolutions
//
//  Created by zhangxu on 1/7/14.
//  Copyright (c) 2014 zhangxu. All rights reserved.
//

#ifndef MyLeetCodeOjSolutions_BinaryTreePostorderTraversal_h
#define MyLeetCodeOjSolutions_BinaryTreePostorderTraversal_h

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Morris Traversal

class Solution {
    
#define VISIT(n) vec_.push_back((n)->val)
#define MOV_LEFT(n) (n) = (n)->left
#define MOV_RIGHT(n) (n) = (n)->right
    
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if( root == NULL) return vec_;
        
        TreeNode dummy(0);
        TreeNode *cur = NULL, *prev = NULL;
        
        dummy.left = root;
        cur = &dummy;
        
        while( cur != NULL)
        {
            if( cur->left == NULL)
            {
                prev = cur;
                MOV_RIGHT(cur);
            }
            else
            {
                TreeNode *node = cur->left;
                while( node->right != NULL && node->right != cur)
                    MOV_RIGHT(node);
                
                if( node->right == NULL)
                {
                    node->right = cur;
                    prev = cur;
                    MOV_LEFT(cur);
                }
                else
                {
                    visitReverse( cur->left, prev);
                    prev->right = NULL;
                    prev = cur;
                    MOV_RIGHT(cur);
                }
            }
        }
        
        return vec_;
    }
    
    void reverse(TreeNode *from, TreeNode *to)
    {
        TreeNode *x = from, *y = from->right, *z = NULL;
        if( from == to) return;
        while( x != to)
        {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }
    
    void visitReverse(TreeNode *from, TreeNode *to)
    {
        TreeNode *p = to;
        reverse( from, to);
        while(true)
        {
            VISIT(p);
            if( p == from) break;
            MOV_RIGHT(p);
        }
        reverse( to, from);
    }
    
    
private:
    vector<int> vec_;
};


#endif
