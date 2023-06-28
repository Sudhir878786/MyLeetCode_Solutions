class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>dist(n,0.0);
        dist[start]=1.0;
        pq.push({0.0,start});
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            for(auto it:adj[cur.second]){
                if(dist[cur.second]*it.second>dist[it.first]){
                    dist[it.first]=dist[cur.second]*it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
            
        }
        return dist[end];
        
        
    }
};