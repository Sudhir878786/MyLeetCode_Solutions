class Solution
{
    public:
        int minSubarray(vector<int> &nums, int p)
        {
            int curr_sum = 0ll, ans = INT_MAX, total, n = nums.size();

            total = accumulate(nums.begin(), nums.end(), 0ll) % p;
            if (total == 0) return 0;	//if already the (sum of array)%p==0 then no need to remove anything i.e. return 0;

            unordered_map<int, int> mp;	// to store the previous (prefix_sum % p) 
            mp[0] = -1;	// case for if some prefix has to be removed

            for (int i = 0; i < n; i++)
            {
                curr_sum = (curr_sum + nums[i]) % p;
                if (mp.find((curr_sum - total + p) % p) != mp.end())
                {
                    ans = min(ans, i - mp[(curr_sum - total + p) % p]);
                }
                mp[curr_sum] = i;
            }
            return ans == n ? -1 : ans;
        }
};