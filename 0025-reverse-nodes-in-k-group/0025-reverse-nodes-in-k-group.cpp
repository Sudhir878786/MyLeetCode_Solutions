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
    int len(ListNode*head)
    {
        ListNode*cur=head;
        int ans=0;
        while(cur){
            ans++;
            cur=cur->next;
        }
        return ans;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*cur=head;
        ListNode* prev=NULL,*next=NULL;
        auto n= len(head);
        if(n<k){
            return head;
        }
        for(int i=0;i<k;i++){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        head->next=reverseKGroup(cur,k);
        return prev;
    }
};