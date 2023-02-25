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
    ListNode*merge(ListNode*l1,ListNode*l2)
    {
        
         ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
        
        curr = curr ->next;
        
        }
        
        //for unqual length linked list
        
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
        
       
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return NULL;
        int  n=lists.size();
        while(lists.size()>1){
            lists.push_back(merge(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
};