class Solution {
public:
    bool isbound(int i,int j,int n,int m)
    {
        return (i==0 || j==0 || i==n-1 || j==m-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isbound(i,j,n,m) and grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    
                }
            }
        }
        int xdir[]={-1,0,1,0};
        int ydir[]={0,1,0,-1};
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r=xdir[i]+cur.first;
                int c=ydir[i]+cur.second;
                if(r>=0 and c>=0 and r<n and c<m and vis[r][c]==0 and grid[r][c]==1){
                    q.push({r,c});
                    vis[r][c]=1;
                }
            }
        }
         int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // check for unvisited land cell
                if(grid[i][j] == 1 & vis[i][j] == 0) 
                    cnt++; 
            }
        }
        return cnt; 
    }
};