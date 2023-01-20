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
       unordered_map<ListNode*,bool>vis;
        ListNode* cur=head;
        while(cur){
            if(vis[cur]==true){
                return cur;
            }
            vis[cur]=true;
            cur=cur->next;
        }
        return nullptr;
        
    }
};