class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j,int m,int n)
    {
        if(i>=n|| j>=m|| i<0 || j<0 || grid[i][j]==0)return 1;
        
        if(grid[i][j]==-1)return 0;
        grid[i][j]=-1;
        return dfs(grid,i+1,j,m,n)+dfs(grid,i-1,j,m,n)+dfs(grid,i,j-1,m,n)+dfs(grid,i,j+1,m,n);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   ans= dfs(grid,i,j,m,n);
                }
            }
        }
        return ans;
    }
};