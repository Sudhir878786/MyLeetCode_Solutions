// class Solution                                    TLE
// {
//     public:
//         int solve(vector<vector < int>> &grid, int k, int i, int j, int sum)
//         {
//            	/// base condition
//             if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
//             {
//                 return 0;
//             }
//             if (i == grid.size() - 1 and j == grid[0].size() - 1)
//             {
//                 sum += grid[i][j];
//                 if (sum % k == 0)
//                 {
//                     return 1;
//                 }
//                 else
//                 {
//                     return 0;
//                 }
//             }
//             int down = solve(grid, k, i + 1, j, sum + grid[i][j]);
//             int right = solve(grid, k, i, j + 1, sum + grid[i][j]);
//             return down + right;
//         }
//     int numberOfPaths(vector<vector < int>> &grid, int k)
//     {
//         return solve(grid, k, 0, 0, 0);
//     }
// };

class Solution
{
    public:
        int solve(vector<vector < int>> &grid, int k, int i, int j, int sum, vector< vector< vector< int>>> &dp)
        {
           	/// base condition
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            {
                return 0;
            }

            if (i == grid.size() - 1 and j == grid[0].size() - 1)
            {
                sum += grid[i][j];
                if (sum % k == 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            if (dp[i][j][sum%k] != -1)
            {
                return dp[i][j][sum%k];
            }
            long  down = (solve(grid, k, i + 1, j, sum + grid[i][j], dp));
            long  right = (solve(grid, k, i, j + 1, sum + grid[i][j], dp));
            return dp[i][j][sum%k] = (down%1000000007 + right%1000000007) % 1000000007;
        }
    int numberOfPaths(vector<vector < int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector< int>>> dp(n, vector<vector < int>> (m, vector<int> (k+1, -1)));
        return solve(grid, k, 0, 0, 0, dp);
    }
};