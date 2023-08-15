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
    ListNode* partition(ListNode* head, int x) {
        ListNode*a=new ListNode(0);
        ListNode*b=new ListNode(0);
        ListNode*h1=a,*h2=b;
        while(head)
        {
            if(head->val<x){
                a->next=head;
                a=a->next;
            }
            else{
                b->next=head;
                b=b->next;
            }
            head=head->next;
        }
        b->next=NULL;
        a->next=h2->next;
        return h1->next;
    }
};