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
    ListNode* sortList(ListNode* head) {
        if(!head){return NULL;}
        if(!head->next){
            return head;
        }
        ListNode*s=head;
        ListNode*f=head;
        while(f->next and f->next->next)
        {
            s=s->next;
            f=f->next->next;
        }
        ListNode*mid=s->next;
        s->next=NULL;
        ListNode*a=sortList(head);
        ListNode*b=sortList(mid);
        return merge(a,b);
        
    }
};