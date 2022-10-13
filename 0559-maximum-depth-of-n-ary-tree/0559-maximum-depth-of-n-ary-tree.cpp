/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

*/
// class Solution
// {
//     public:
//         int maxDepth(Node *root)
//         {
//             if (!root) return 0;
//             int count = 0;
//             for (auto x: root->children)
//             {
//                 count = max(count, maxDepth(x));
//             }
//             return count+1;
//         }
// };

class Solution
{
    public:
        int maxDepth(Node *root)
        {
            if (!root) return 0;
            stack<pair<Node*, int>> st;
            int ans = 0;
            st.push({ root,
                1 });
            while (!st.empty())
            {
                Node *cur = st.top().first;
                int dep = st.top().second;
                st.pop();
                for (auto n: cur->children)
                {
                    st.push({ n, dep + 1 });
                }
                ans = max(ans, dep);
            }
            return ans;
        }
};