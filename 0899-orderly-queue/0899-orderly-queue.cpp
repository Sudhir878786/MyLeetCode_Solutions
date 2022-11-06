class Solution
{
    public:
        string orderlyQueue(string s, int k)
        {
            string ans = "";
            if (k > 1)
            {
                sort(s.begin(), s.end());
                return s;
            }
            int n = s.size();
            ans = s;
            s += s;
            cout << s << endl;
            for (int i = 0; i < n; i++)
            {
                if (s.substr(i, n) < ans)
                {
                    ans = s.substr(i, n);
                    cout << ans << endl;
                }
            }
            return ans;
        }
};