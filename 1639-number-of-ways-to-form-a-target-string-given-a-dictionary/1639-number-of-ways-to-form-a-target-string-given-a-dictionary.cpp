class Solution {
public:
    const int MOD = 1000000007;
    int recur(int i,int j,vector<string> &words,string &target,vector<vector<int>> &dp)
    {
        if(j == target.size())
        {
            return 1;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int n = words[0].size();
        if(i == n || n - i < target.size() - j)
        {
            return 0;
        }

        long long take = 0;
        for(int idx=0;idx<words.size();idx++)
        {
            if(words[idx][i] == target[j])
            {
                take += recur(i + 1,j+1,words,target,dp) % MOD;
            }
        }
        int not_take = recur(i + 1,j,words,target,dp) % MOD;

        return dp[i][j] = (take + not_take) % MOD;
    }

    int numWays(vector<string>& words, string target) {
        int n = words[0].size(), m = target.size();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,-1));
        return recur(0,0,words,target,dp);
    }
};