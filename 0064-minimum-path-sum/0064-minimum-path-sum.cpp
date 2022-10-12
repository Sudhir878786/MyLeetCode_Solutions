class Solution
{
    public:
        int maxx = INT_MIN;
    int solve(vector<vector < int>> &grid, int i, int j, int sum, vector<vector < int>> &dp)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return 10000;
        }
        if (i == grid.size() - 1 and j == grid[0].size() - 1)
        {
            dp[i][j] = grid[i][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int down = grid[i][j] + solve(grid, i + 1, j, sum, dp);
        int right = grid[i][j] + solve(grid, i, j + 1, sum, dp);

        return dp[i][j] = min(down, right);
    }
    int minPathSum(vector<vector < int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector < int>> dp(m , vector<int> (n , -1));
        return solve(grid, 0, 0, 0, dp);
    }
};