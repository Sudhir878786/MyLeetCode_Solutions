class Solution
{
    public:
        vector<int> divisibilityArray(string word, int m)
        {
            int n = word.length();
            vector<int> div(n, 0);
            long long prefix = 0;
            for (int i = 0; i < n; i++)
            {
                prefix = (prefix *10 +  (long long) (word[i] - '0')) % m;
                if (prefix == 0)
                {
                    div[i] = 1;
                }
            }
            return div;
        }
};