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
    bool isPalindrome(ListNode* head) {
        ListNode*cur=head;
        stack<int>st;
        while(cur!=NULL){
            st.push(cur->val);
            cur=cur->next;
        }
        while(head!=NULL and !st.empty()){
             int x=st.top();
            st.pop();
            if(head->val!=x){
                return false;
            }
            
            head=head->next;
        }
        return 1;
    }
};