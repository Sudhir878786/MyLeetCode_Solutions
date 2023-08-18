class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>adj(n);
        for(auto x:roads){
            adj[x[0]].insert(x[1]);
             adj[x[1]].insert(x[0]);
        }
        int ans=INT_MIN;
        for(int i=0;i<adj.size();i++){
            for(int j=i+1;j<adj.size();j++){
                int rank=adj[i].size()+adj[j].size();
                if(adj[j].count(i)){
                    rank-=1;
                }
                ans=max(ans,rank);
            }
            
        }
        return ans;
    }
};