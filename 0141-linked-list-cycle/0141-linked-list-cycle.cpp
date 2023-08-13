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
    bool hasCycle(ListNode *head) {
        ListNode* cur=head;
        unordered_map<ListNode*,int>mp;
        while(cur!=NULL){
            if(mp[cur]==true){
                return true;
            }
            
            mp[cur]=1;
            cur=cur->next;
        }
        return false;
    }
};