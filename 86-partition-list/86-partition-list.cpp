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
        ListNode* head1=new ListNode(0);  // store node less than x
        ListNode* head2=new ListNode(0);  // store node gret or equal to x
        ListNode* h1=head1;
        ListNode* h2=head2;
        while(head){
            if(head->val<x){
                head1->next=head;
                head1=head1->next;
                
            }
            else{
                head2->next=head;
                head2=head2->next;
            }
            head=head->next;
        }
        head2->next=NULL;    // make the last node ->next of head2 NULL;
        head1->next=h2->next; // join the head2 with head1 
        return h1->next;
    }
};