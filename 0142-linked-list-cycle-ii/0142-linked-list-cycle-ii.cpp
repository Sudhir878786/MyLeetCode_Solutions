/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode*slow=head;
       ListNode*fast=head;
       ListNode*enter=head; 
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                while(enter!=slow)
                {
                    enter=enter->next;
                    slow=slow->next;
                }
                return slow;
            }

        }
        return NULL;
    }
};