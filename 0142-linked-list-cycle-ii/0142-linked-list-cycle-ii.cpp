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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool>mp;
        ListNode*cur=head;
        while(cur){
            if(mp[cur]!=false){
                return cur;
            }
            mp[cur]=true;
            
            cur=cur->next;
        }
        return cur;
    }
};