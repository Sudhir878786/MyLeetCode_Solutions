class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head->next) return;
        // step 1: find the middle pointer of the linked list
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;

        // step 2: reverse the last half linked list
        ListNode *p = mid, *q = mid->next, *pp = NULL, *qq = NULL;
        mid->next = NULL;
        while (q) {
            pp = p;
            p = q;
            q = q->next;
            p->next = pp;
        }
        mid = p;

        // step 3: merge first half and reversed last half
        p = head;
        q = mid;
        while (q) {
            pp = p; qq = q;
            p = p->next; q = q->next;
            pp->next = qq; qq->next = p;
        }
    }
};