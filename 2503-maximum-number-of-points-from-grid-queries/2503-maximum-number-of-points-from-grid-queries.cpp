class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int>ans(queries.size());
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>>q(queries.size());
        for(int i=0;i<queries.size();i++){
            q[i]={queries[i],i};
        }
        int res=0;
        sort(begin(q),end(q));
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=true;
        vector<vector<int>>dir={{1,0},{0,1},{0,-1},{-1,0}};
        for(int i=0;i<queries.size();i++){
            while(pq.size() and pq.top().first<q[i].first){
                auto cur=pq.top();
                res++;
                pq.pop();
                for(int i=0;i<4;i++){
                    int r=cur.second.first+dir[i][0];
                    int c=cur.second.second+dir[i][1];
                    if(r>=0 and c>=0 and r<n and c<m and vis[r][c]==false){
                        vis[r][c]=true;
                        pq.push({grid[r][c],{r,c}});
                    }
                }
            }
            ans[q[i].second]=res;
        }
        return ans;
            
    }
};