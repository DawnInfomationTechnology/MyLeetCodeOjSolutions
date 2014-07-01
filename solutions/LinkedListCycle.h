//
//  LinkedListCycle.h
//  MyLeetCodeOjSolutions
//
//  Created by zhangxu on 1/7/14.
//  Copyright (c) 2014 zhangxu. All rights reserved.
//

#ifndef MyLeetCodeOjSolutions_LinkedListCycle_h
#define MyLeetCodeOjSolutions_LinkedListCycle_h

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if( head == NULL) return false;
        
        ListNode *fast = head, *slow = head;
        while( fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if( fast == slow) return true;
        }
        return false;
    }
};


#endif
