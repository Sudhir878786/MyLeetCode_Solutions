class Solution
{
    public:
        double find(int N, int K, int r, int c, vector<vector<vector< double>>> &dp)
        {
            if (r < 0 || c < 0 || r >= N || c >= N) return 0;
            if (K == 0) return 1;
            if (dp[r][c][K] != 0) return dp[r][c][K];
            double p = find(N, K - 1, r + 1, c + 2, dp) + find(N, K - 1, r - 1, c - 2, dp) +
                find(N, K - 1, r + 2, c + 1, dp) + find(N, K - 1, r - 2, c - 1, dp) +
                find(N, K - 1, r + 1, c - 2, dp) + find(N, K - 1, r - 1, c + 2, dp) +
                find(N, K - 1, r + 2, c - 1, dp) + find(N, K - 1, r - 2, c + 1, dp);
            p /= 8;

            return dp[r][c][K] = p;
        }
    double knightProbability(int N, int K, int r, int c)
    {
        vector<vector<vector< double>>> dp(N, vector<vector < double>> (N, vector<double> (K + 1)));	//[row][col][step]
        return find(N, K, r, c, dp);
    }
};