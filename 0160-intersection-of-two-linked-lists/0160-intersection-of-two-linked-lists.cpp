/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>st;
        ListNode*cur1=headA;
        while(cur1){
            st.insert(cur1);
            cur1=cur1->next;
            
        }
        cur1=headB;
        while(cur1){
            if(st.find(cur1)!=st.end()){
                return cur1;
            }
            cur1=cur1->next;
        }
        return cur1;
    }
};