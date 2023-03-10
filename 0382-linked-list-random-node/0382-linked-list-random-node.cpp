/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode * headd;
    Solution(ListNode *head)
    {
        headd = head;
    }

    int getRandom()
    {
        int ans = 0;
        int len = 1;
        ListNode *cur = headd;
        while (cur)
        {
            if (rand() % len == 0) ans = cur->val;

            len++;
            cur = cur->next;
        }
        return ans;
    }
};

/**
 *Your Solution object will be instantiated and called as such:
 *Solution* obj = new Solution(head);
 *int param_1 = obj->getRandom();
 */