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

// This method does nothing but swaps the values of nodes. Take a stack and push the values of nodes in range [left, right]. Now during second iteration in the same range, take stack.top() ans replace it with node value.

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int>st;
        int i=1;
        ListNode*curr=head;
        while(i<=right){
            if(i>=left){
                st.push(curr->val);
            }
            curr=curr->next;
            i++;
        }
        i=1;
        curr=head;
        while(i<=right){
            if(i>=left){
                curr->val=st.top();
                st.pop();
            }
            curr=curr->next;
            i++;
        }
        return head;
    }
};