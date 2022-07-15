class Solution {
public:
  
    int dfs(int i,int j,vector<vector<int>>&grid,int n,int m)
    {
      if(i<0 || j<0 ||i>=n || j>=m || !grid[i][j])return 0;
      grid[i][j]=0;
      return 1+dfs(i-1,j,grid,n,m)+dfs(i+1,j,grid,n,m)+dfs(i,j-1,grid,n,m)+dfs(i,j+1,grid,n,m);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
      int m=grid[0].size();
      int ans=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(grid[i][j]){
            ans=max(ans,dfs(i,j,grid,n,m));
          }
        }
      }
      return ans;
    }
};