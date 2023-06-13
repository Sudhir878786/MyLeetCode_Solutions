class Solution
{
    public:
        int func(int j, int i, int n, int m, vector<vector < int>> &matrix, vector< vector< int>> &dp)
        {
            if (i < 0 || i >= n || j < 0 || j >= m)
            {
                return 1e9;
            }
            if (i == n - 1)
            {
                return matrix[i][j];
            }
            if (dp[i][j] != -1)
            {
                return dp[i][j];
            }
            int a = matrix[i][j] + func(j - 1, i + 1, n, m, matrix, dp);
            int b = matrix[i][j] + func(j + 1, i + 1, n, m, matrix, dp);
            int c = matrix[i][j] + func(j, i + 1, n, m, matrix, dp);
            return dp[i][j] = min(a, min(b, c));
        }
    int minFallingPathSum(vector<vector < int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));
        int ans = INT_MAX;
        // for (int j = 0; j < m; j++)
        // {
        //     ans = min(ans, func(j, 0, n, m, matrix, dp));
        // }
        // return ans;
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0){
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==m-1){
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                }
                else {
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
                }
            }
        }
        for(int j=0;j<m;j++){
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};