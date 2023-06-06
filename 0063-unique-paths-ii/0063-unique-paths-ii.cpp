class Solution {
public:
      int ans = 0;
    int dfs(int i, int j, vector<vector < int>> &grid, int n, int m, vector< vector< int>> &dp)

    {
        if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 1)
        {
            return 0;
        }
        if (i == n - 1 and j == m - 1) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int a = dfs(i + 1, j, grid, n, m, dp);
        int b = dfs(i, j + 1, grid, n, m, dp);
        ans = a + b;
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(grid[0][0]!=1){
            return dfs(0, 0, grid, n, m, dp);
        }
        return 0;
    }
};