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
        ListNode*cur=head;
        unordered_map<ListNode*,bool>vis;
        while(cur){
            if(vis[cur]){
                return true;
            }
            vis[cur]=true;
            
            cur=cur->next;
        }
        return false;
    }
};