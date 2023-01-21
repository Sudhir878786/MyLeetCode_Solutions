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
       ListNode* current = head;
    stack<ListNode*> s;
    ListNode* newHead = nullptr;
    ListNode* prevTail = nullptr;
    while (current != nullptr) {
        // Push k elements onto the stack
        for (int i = 0; i < k && current != nullptr; i++) {
            s.push(current);
            current = current->next;
        }
        if (s.size() == k) {
            // Pop k elements off the stack and update next pointers
            ListNode* newTail = s.top();
            s.pop();
            ListNode* curr = newTail;
            while (!s.empty()) {
                curr->next = s.top();
                s.pop();
                curr = curr->next;
            }
            curr->next = current;
            // Update newHead and prevTail pointers
            if (newHead == nullptr) {
                newHead = newTail;
            } else {
                prevTail->next = newTail;
            }
            prevTail = curr;
        }
    }
    return newHead ;
}
};