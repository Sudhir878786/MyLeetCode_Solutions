class Solution
{
    public:
        bool check(vector<int> &a, vector<int> &b)
        {
            long long int A = (long long int)(b[0] - a[0]) *(long long int)(b[0] - a[0]);
            long long int B = (long long int)(b[1] - a[1]) *(long long int)(b[1] - a[1]);
            long long int C = (long long int) a[2] *a[2];
            if (A + B <= C) return true;
            else return false;
        }
    void dfs(int node, vector<int> adlist[], int &cnt, vector<int> &vis)
    {
        vis[node] = 1;
        cnt++;
        for (auto i: adlist[node])
        {
            if (vis[i] == -1) dfs(i, adlist, cnt, vis);
        }
    }
    int maximumDetonation(vector<vector < int>> &bombs)
    {
        int n = bombs.size();
        int m = bombs[0].size();
        vector<int> adj[n + 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check(bombs[i], bombs[j]))
                {
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < n; i++)	
        {
            int cnt = 0;

            vector<int> vis(n, -1);

            dfs(i, adj, cnt, vis);

            ans = max(ans, cnt);
        }

        return ans;
    }
};