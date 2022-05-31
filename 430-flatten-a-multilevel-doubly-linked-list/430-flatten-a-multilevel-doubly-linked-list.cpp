/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return NULL;
        Node* ptr = head;
        stack<Node*> st;
        //cout<< head->val << " ";
        while(head->next || head->child || !st.empty())
        {
            if(head->next || head->child)
            {
                if(head->child)
                {
                    st.push(head->next);
                    head->child->prev = head;
                    head->next = head->child;
                    head->child = NULL;
                    head = head->next;
                }
                else
                {
                    head = head->next;
                }
            }
            else
            {
                if(st.top() == NULL)
                {
                    head->next = NULL;
                    st.pop();
                }
                else
                {
                    st.top()->prev = head;
                    head->next = st.top();
                    st.pop();
                    head = head->next;   
                }
            }
        }
        return ptr;
    }
};