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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* l=head;
        ListNode*r=head;
        ListNode*cur=head;
        
        int count=1;
        while(cur!=NULL){
            
            if(count<k){
                l=l->next;
            }
            if(count>k){
                r=r->next;
            }
            count++;
            cur=cur->next;
        }
        swap(l->val,r->val);
        return head;
    }
};