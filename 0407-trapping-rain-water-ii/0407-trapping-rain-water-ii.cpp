class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    int trapRainWater(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        int ans=0;
        vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
        priority_queue<p,vector<p>,greater<p>>pq;  /// min heap 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){  // store the  boundary 
                    pq.push({h[i][j],{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        // bfs
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            for(int i=0;i<4;i++){
                int r=cur.second.first+dir[i][0];
                int c=cur.second.second+dir[i][1];
                if(r>=0 and c>=0 and r<n and c<m and vis[r][c]==false){
                    ans+=max(0,cur.first-h[r][c]);
                    if(cur.first>h[r][c]){
                        pq.push({cur.first,{r,c}});
                    }
                    else{
                        pq.push({h[r][c],{r,c}});
                    }
                    vis[r][c]=true;
                }
            }
            
        }
        return ans;
        
    }
};