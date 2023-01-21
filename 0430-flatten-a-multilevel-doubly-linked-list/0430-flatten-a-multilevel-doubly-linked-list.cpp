/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* childch
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node*cur=head;
        stack<Node*>st;
        Node*tail=head;
        // if(!head)return head;
        while(cur)
        {
            if(cur->child){
                Node*child=cur->child;
                if(cur->next!=NULL){
                    st.push(cur->next);
                    // cur=cur->next;
                    cur->next->prev=NULL;

                }
                cur->next=child;
                child->prev=cur;
                cur->child=NULL;
                
            }
            tail=cur;
            cur=cur->next;
        
            
        }
        while(!st.empty()){
            cur=st.top();
            st.pop();
            tail->next=cur;
            cur->prev=tail;
            while(cur!=NULL){
                tail=cur;
                cur=cur->next;
            }
            
        }
        return  head;
        
    }
};