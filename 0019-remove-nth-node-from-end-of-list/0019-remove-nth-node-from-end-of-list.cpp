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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*cur=head;
        int len=0;
        
        while(cur!=NULL){
            cur=cur->next;
            len++;
        }
        if(len==n){
            // if the node itself it to  be dlete then 
            return head->next;
        }
        cur=head;
        for(int i=1;i<len-n;i++){
            cur=cur->next;
        }
        cur->next=cur->next->next;
        return head;
    }
};