class Solution
{
    public:
        bool func(string &s, vector<string> &word, int ind, set<string> &st, vector< int > &dp)
        {
            if (ind == s.size())
            {
                return true;
            }
            if (dp[ind] != -1)
            {
                return dp[ind];
            }

            for (int i = ind; i < s.size(); i++)
            {
                string cur = s.substr(ind, i - ind + 1);
                if (st.find(cur) != st.end() and func(s, word, i + 1, st, dp))
                {
                    return dp[ind] = true;
                }
            }
            return dp[ind] = false;
        }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1, -1);
        return func(s, wordDict, 0, st, dp);
    }
};