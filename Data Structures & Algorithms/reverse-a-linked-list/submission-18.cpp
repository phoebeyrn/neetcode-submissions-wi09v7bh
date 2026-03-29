/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        //temp variable for storage
        ListNode * temp = nullptr;
        //know what current node we're on
        ListNode * curr = head;
        //point to previous node in changing list
        ListNode * prev = nullptr;

        //edge case 1: if we're passing in a null list
        if(!head) return nullptr;

        //reverse the linked list
        while(curr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
