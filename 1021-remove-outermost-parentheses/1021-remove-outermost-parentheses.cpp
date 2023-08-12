class Solution
{
    public:
        string removeOuterParentheses(string s)
        {
            string ans = "";
            int cnt = 0;
            for (auto it: s)
            {
                if (it == '(')
                {
                    if (cnt++)
                    {
                        ans += '(';
                    }
                }
                else
                {
                    if (--cnt)
                    {
                        ans += ')';
                    }
                }
            }
            return ans;
        }
};