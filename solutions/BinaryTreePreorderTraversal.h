//
//  BinaryTreePreorderTraversal .h
//  MyLeetCodeOjSolutions
//
//  Created by zhangxu on 1/7/14.
//  Copyright (c) 2014 zhangxu. All rights reserved.
//

#ifndef MyLeetCodeOjSolutions_BinaryTreePreorderTraversal__h
#define MyLeetCodeOjSolutions_BinaryTreePreorderTraversal__h

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        if( root == NULL) return vec_;
        
        TreeNode *cur = root, *prev = NULL;
        
        while( cur != NULL)
        {
            if( cur->left == NULL)
            {
                VISIT(cur);
                prev = cur;
                MOV_RIGHT(cur);
            }
            else
            {
                TreeNode *node = cur->left;
                while(node->right != NULL && node->right != cur)
                    MOV_RIGHT(node);
                
                if( node->right == NULL)
                {
                    VISIT(cur);
                    node->right = cur;
                    prev = cur;
                    MOV_LEFT(cur);
                }
                else
                {
                    node->right = NULL;
                    MOV_RIGHT(cur);
                }
            }
        }
        
        return vec_;
    }
private:
    vector<int> vec_;
};


#endif
