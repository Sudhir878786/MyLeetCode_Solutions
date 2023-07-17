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
    ListNode* reverse(ListNode*l)
    {
        ListNode*cur=l,*prev=NULL,*next=NULL;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        l=prev;
        return l;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 and !l2){
            return NULL;
        }
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode*cur=new ListNode(0);
        ListNode*tail=cur;
        int carry=0;
        while(l1 or l2 or carry)
        {
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode *ans=new ListNode(sum%10);
            tail->next=ans;
            tail=tail->next;
        }
        cur=reverse(cur->next);
        return cur;
    }
};