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
   ListNode* reverseEvenLengthGroups(ListNode *head)
		{
			//  if LL has 1 or 2 nodes only
			if (head->next == nullptr || head->next->next == nullptr) return head;

			ListNode *node = head;
			int group = 1;

			while (node != nullptr && node->next != nullptr)
			{
				group++;

				int countNodes = 0;
				ListNode *temp = node->next;
				while (temp != nullptr && countNodes < group)
				{
					temp = temp->next;
					countNodes++;
				}

				if (countNodes % 2 == 0)
				{
					ListNode *curr = node->next, *prev = nullptr, *next = nullptr;
					for (int i = 0; i < countNodes; i++)
					{
						next = curr->next;
						curr->next = prev;
						prev = curr;
						curr = next;
					}

					ListNode *tail = node->next;
					tail->next = curr;
					node->next = prev;
					node = tail;
				}
				else
				{
					for (int i = 0; i < countNodes; i++)
					{
						node = node->next;
					}
				}
			}

			return head;
		
    }
};