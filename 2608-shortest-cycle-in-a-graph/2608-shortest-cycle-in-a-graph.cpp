class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // run bfs from all node and store their parernt and distance
        // O(n3)
        vector<vector<int>>adj(n);
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            vector<int>dist(n,INT_MAX);
            vector<int>par(n,-1);
            dist[i]=0;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                auto cur=q.front();
                q.pop();
                for(auto next:adj[cur]){
                    if(dist[next]==INT_MAX){
                        dist[next]=dist[cur]+1;
                        par[next]=cur;
                        q.push(next);
                    }
                    else if(par[cur]!=next){ans=min(ans,dist[cur]+dist[next]+1);}
                }
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};