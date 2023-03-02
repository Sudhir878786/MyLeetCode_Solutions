class Solution
{
    public:
       	// intitution is  
       	// lets think of maximum number of step rewq to make both equal;
       	// which is lenght ofword1+word2;
       	// now finding the  lenght of longest commmon subseq 
       	// and subracting them form both the string lenght and add them

        int minDistance(string word1, string word2)
        {
            int ans = 0;
            int n = word1.size();
            int m = word2.size();
            int lcs = 0;
            vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));
            for (int i = 0; i <= n; i++)
            {
                dp[i][0] = 0;
            }
            for (int i = 0; i <= m; i++)
            {
                dp[0][i] = 0;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (word1[i - 1] == word2[j - 1])
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
                lcs = dp[n][m];
            }

            return (n - lcs) + (m - lcs);
        }
};