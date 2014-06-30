//
//  SortList .h
//  MyLeetCodeOjSolutions
//
//  Created by zhangxu on 30/6/14.
//  Copyright (c) 2014 zhangxu. All rights reserved.
//

#ifndef MyLeetCodeOjSolutions_SortList__h
#define MyLeetCodeOjSolutions_SortList__h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// use merge sort, asc

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if( head == NULL) return NULL;
        if( head->next == NULL) return head;
        
        ListNode *left = head, *right = head;
        
        // find the middle node
        while( left->next != NULL && right->next != NULL && right->next->next != NULL)
        {
            right = right->next->next;
            left = left->next;
        }
        
        right = left->next;
        left->next = NULL;
        left = head;
        
        left = sortList( left);
        right = sortList( right);
        
        return merge( left, right);
    }
    
    ListNode *merge( ListNode* l1, ListNode* l2)
    {
        if( l1 == NULL) return l2;
        else if( l2 == NULL) return l1;
        
        ListNode *head = NULL, *p = NULL;
        if( l1->val > l2->val)
        {
            head = l2;
            l2 = l2->next;
        }
        else
        {
            head = l1;
            l1 = l1->next;
        }
        p = head;
        
        while ( l1 != NULL && l2 != NULL)
        {
            if( l1->val > l2->val)
            {
                p->next = l2;
                l2 = l2->next;
            }
            else
            {
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        
        if( l1 != NULL) p->next = l1;
        else if( l2 != NULL) p->next = l2;
        
        return head;
    }
};


#endif
