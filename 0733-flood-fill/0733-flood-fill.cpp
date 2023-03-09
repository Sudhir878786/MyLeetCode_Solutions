class Solution {
public:
    void dfs(vector<vector<int>>& grid, int sr, int sc,int n,int m, int color,int neww)
    {
        if(sr>=n || sc>=m || sr<0 || sc<0 || grid[sr][sc]!=neww){
            return ;
        }
        grid[sr][sc]=color;
        dfs(grid,sr+1,sc,n,m,color,neww);
        dfs(grid,sr-1,sc,n,m,color,neww);
        dfs(grid,sr,sc+1,n,m,color,neww);
        dfs(grid,sr,sc-1,n,m,color,neww);
    }
        
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[sr][sc]!=color){
            dfs(grid,sr,sc,n,m,color,grid[sr][sc]);
        }
        return grid;
    }
};