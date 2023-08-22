class Solution {
public:

    // bfs for finding 'm' groups if possible
    int bfs(vector<vector<int>> g, int u, int n) {
        queue<int> q;
        q.push(u);
        // vector to check which node is in which group
        vector<int> vt(n, -1);
        vt[u] = 1;  // Take node 'u' in 'Group 1'
        int ans = 1, f = 1;
        while(!q.empty()) {
            int i = q.front();
            ans = max(ans, vt[i]);
            q.pop();
            for(auto &v : g[i]) {
                // Check If the node is already visited, then is it following |y - x| = 1 condition
                if(vt[v] != -1 && abs(vt[i] - vt[v]) != 1) {
                    return -1;
                }
                if(vt[v] != -1) continue;
                vt[v] = vt[i] + 1;
                q.push(v);
            }
            if(!f)  break;
        }
        return ans;
    }

    // dfs for finding connect components
    void dfs(vector<vector<int>> &g, int u, vector<bool> &vt, vector<int> &a) {
        a.push_back(u);
        vt[u] = true;
        for(auto &v : g[u]) {
            if(vt[v])   continue;
            dfs(g,v,vt,a);
        }
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Create adj list
        vector<vector<int>> g(n);
        for(auto edge : edges) {
            g[edge[0] - 1].push_back(edge[1] - 1);
            g[edge[1] - 1].push_back(edge[0] - 1);
        }


        // Create list of Connected Components
        vector<vector<int>> conComp;
        vector<bool> vt(n, false); // visited vector
        vector<int> tmp; // temporary vector for storing connect components
        for(int i = 0 ; i < n ; i++) {
            if(!vt[i]) {
                dfs(g,i,vt,tmp);
                conComp.push_back(tmp);
                tmp.clear();
            }
        }

        int res = 0;
        // Traverse through all the components
        for(auto &comp : conComp) {
            int ans = -1;
            // In each components, try which node gives the best answer
            for(int i : comp) {
                ans = max(ans, bfs(g,i,n));
            }
            // Even after trying all nodes if we don't find an answer,
            // then it is not possible to make a group
            if(ans == -1) {
                return -1;
            }
            else res += ans;
        }
        return res;
    }
};