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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*cur=head;
        if(!head || !head->next || k==0 ){
            return head;
        }
        int len=1;
        while(cur->next){
            cur=cur->next;
            len++;
        }
        cur->next=head;
        k=k%len;
        while(--len>=k){
            cur=cur->next;
        }
        ListNode*tail=cur->next;
        cur->next=NULL;
        return tail;
    }
};