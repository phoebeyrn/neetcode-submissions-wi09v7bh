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
    void reorderList(ListNode* head) 
    {
        if(!head) return;

        ListNode * fast = head;
        ListNode * slow = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode * l2 = slow->next;
        slow->next = nullptr;

        ListNode * prev = nullptr;
        ListNode * curr = l2;

        while(curr)
        {
            ListNode * nextL2 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextL2;
        }

        ListNode * head1 = head;
        ListNode * head2 = prev;

        ListNode dummy(0);
        ListNode * merged = &dummy;

        while(head1 && head2)
        {
            ListNode* next1 = head1->next;
            ListNode* next2 = head2->next;

            head1->next = head2;
            head2->next = next1;

            head1 = next1;
            head2 = next2;
        }
    }
};
