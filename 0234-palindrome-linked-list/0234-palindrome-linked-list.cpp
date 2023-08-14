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
        stack<ListNode*>st;
        ListNode*cur=head;
        while(cur!=NULL){
            st.push(cur);
            cur=cur->next;
        }
        while(head!=NULL and !st.empty()){
            auto it=st.top()->val;
            st.pop();
            if(head->val!=it){
                return false;
            }
            head=head->next;
        }
        return true;
    }
};