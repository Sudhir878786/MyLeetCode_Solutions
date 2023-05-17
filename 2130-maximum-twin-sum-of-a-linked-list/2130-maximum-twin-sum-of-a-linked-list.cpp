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
    int pairSum(ListNode* head) {
        int ans=0;
        int n=0;
        
        ListNode* cur=head;
        ListNode* prev=head;
        stack<ListNode*>s;
        while(cur){
            n++;
            s.push(cur);
            cur=cur->next;
        }
        while(s.size()>n/2){
            cur=s.top();
            // cout<<prev->val+cur->val<<endl;
            ans=max(ans,prev->val+cur->val);
            s.pop();
            prev=prev->next;
        }

        return ans;
    }
};