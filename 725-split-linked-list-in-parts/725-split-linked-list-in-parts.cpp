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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         ListNode *ptr = head, *pos = NULL;
        int cnt = 0;
        while(ptr){
            cnt++;
            ptr = ptr->next;
        }
        int numEach = cnt / k;
        int extraEach = cnt % k, ind = 0;
        vector<ListNode *> ans;
        pos = head;
        
        while(pos){
            ListNode *nhead = pos, *prev = NULL;
            ans.push_back(nhead);
            for(int i=0;i<numEach;i++)
            {
                prev = pos;
                pos = pos->next;
            }
            if(extraEach){
                prev = pos;
                pos = pos->next;
                extraEach--;
            }
            prev->next = NULL;
        }
        
        while(ans.size() < k){
            ans.push_back(NULL);
        }
        return ans;
    }

};