//
//  LinkedListCycleII.h
//  MyLeetCodeOjSolutions
//
//  Created by zhangxu on 1/7/14.
//  Copyright (c) 2014 zhangxu. All rights reserved.
//

#ifndef MyLeetCodeOjSolutions_LinkedListCycleII_h
#define MyLeetCodeOjSolutions_LinkedListCycleII_h

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
    ListNode *detectCycle(ListNode *head)
    {
        if( head == NULL) return NULL;
        
        bool hasCycle = false;
        ListNode *fast = head, *slow = head;
        while( fast->next != NULL && fast->next->next != NULL)
        {
            if( !hasCycle)
            {
                fast = fast->next->next;
                slow = slow->next;
                if( fast == slow)
                {
                    slow = head;
                    hasCycle = true;
                }
            }
            else
            {
                if( slow == fast) return slow;
                fast = fast->next;
                slow = slow->next;
            }
        }
        return NULL;
    }
};


#endif
