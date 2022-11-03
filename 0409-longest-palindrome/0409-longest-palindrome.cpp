class Solution
{
    public:
        int longestPalindrome(string s)
        {
            unordered_map<char, int> mp;
            for (int i = 0; i < s.size(); i++)
            {
                mp[s[i]]++;
            }
            int ans = 0;
            int count = 0;
            for (auto it: mp)
            {
                if (it.second % 2 != 0)
                {
                    count++;
                }
            }
            if (count > 1)
            {
               return  s.size() - count + 1;
            }
            return s.size();
        }
};