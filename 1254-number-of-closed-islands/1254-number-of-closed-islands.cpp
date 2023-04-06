class Solution {
public:
    bool dfs(int x,int y,int n,int m,vector<vector<int>>&grid){
        if(x<0 || y<0 || x>=n || y>=m){
            return false;
        }
        if(grid[x][y]>0){
            return true;
        }
        grid[x][y]=2;
        return dfs(x+1,y,n,m,grid)*dfs(x-1,y,n,m,grid)*dfs(x,y+1,n,m,grid)*dfs(x,y-1,n,m,grid);
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for (int i = 0; i <n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 0)
                    cnt += dfs(i, j,n,m, grid);
        return cnt;
    }
};