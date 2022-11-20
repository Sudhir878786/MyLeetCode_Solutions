class Solution {
public:
     vector<int>depth;
     vector<int>sum;
    vector<int>sub;
    vector<vector<int>>adj;
    
    void dfs(int par,int d=-1)
    {
        sub[par]=1;
        for(auto x:adj[par]){
            if(x==d){
                continue;
            }
            depth[x]=depth[par]+1;
            dfs(x,par);
            sub[par]+=sub[x];
        }
    }
    void dfs2(int i,int n,int p=-1)
    {
        for(auto c:adj[i]){
            if(c==p)continue;
            sum[c]=sum[i]-sub[c]+(n-sub[c]);
            dfs2(c,n,i);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        adj.resize(n);
        sub.resize(n);
        for(int i=0;i<n-1;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        depth.resize(n);
        sum.resize(n);
        dfs(0);
       
        // dfs2(depth,sum);
        for(int i=0;i<n;i++){
            sum[0]+=depth[i];
        }
        
        dfs2(0,n);
        

        return sum;
        
    }
};