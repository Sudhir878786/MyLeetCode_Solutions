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
   ListNode* reverseKGroup(ListNode* head, int k) {
if(head==NULL && head->next==NULL)
return NULL;
ListNode* curr= head;
ListNode* prev= NULL;
ListNode* forward =NULL;
int cnt=0;
while(curr!=NULL && cnt<k )
{
forward= curr->next;
curr->next= prev;
prev= curr;
curr= forward;
cnt++;
}
if(curr == NULL && cnt < k)
{
while(prev != NULL)
{
forward = prev -> next;
prev -> next = curr;
curr = prev;
prev = forward;
}
return curr;
}
if(forward!= NULL)
{
head->next= reverseKGroup(forward,k);
}
return prev;


    }
};