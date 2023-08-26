class Solution
{
    public:
        bool static cmp(vector<int> &a, vector<int> &b)
        {
            if (a[0] == b[0])
            {
                return a[1] > b[1];
            }
            else
            {
                return a[0] < b[0];
            }
        }
    int maxEnvelopes(vector<vector < int>> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        vector<int> cur;
        for (auto it: nums)
        {
            // cout << it[0] << it[1] << " " << endl;
            if (cur.empty() || cur.back() < it[1])
            {
                cur.push_back(it[1]);
            }
            else
            {
                auto x = lower_bound(cur.begin(), cur.end(), it[1]);
                *x = it[1];
            }
        }

        return cur.size();
    }
};