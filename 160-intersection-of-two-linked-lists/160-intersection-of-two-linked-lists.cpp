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
        ListNode* ptr1=headA;
 ListNode* ptr2=headB;
 
 int headA_len=0;
 int headB_len=0;
 
 while(ptr1!=NULL)
 {
     headA_len++;
     ptr1=ptr1->next;
 }
 
 while(ptr2!=NULL)
 {
     headB_len++;
     ptr2=ptr2->next;
 }
 
 ptr1=headA;
 ptr2=headB;
 
 while(headA_len>headB_len)
 {
     ptr1=ptr1->next;
     headA_len--;
 }
 
 while(headB_len>headA_len)
 {
     ptr2=ptr2->next;
     headB_len--;
 }
 
 while(ptr1!=NULL)
 {
     if(ptr1==ptr2)
         return ptr1;
     
     ptr1=ptr1->next;
     ptr2=ptr2->next;
 }
 
 return NULL;
}
};