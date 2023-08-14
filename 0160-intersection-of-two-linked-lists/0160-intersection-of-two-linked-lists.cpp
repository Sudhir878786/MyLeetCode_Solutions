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
        set<ListNode*>st;
        ListNode*cur=headA;
        while(cur){
            st.insert(cur);
            cur=cur->next;
        }
        cur=headB;
        while(cur){
            if(st.find(cur)!=st.end()){
                return cur;
            }
            cur=cur->next;
        }
        return NULL;
    }
};