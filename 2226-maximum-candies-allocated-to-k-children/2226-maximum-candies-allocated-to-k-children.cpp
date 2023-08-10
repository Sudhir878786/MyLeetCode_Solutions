class Solution
{
    public:
       	// bool func(vector<int> &nums, int mid, int k)
       	// {
       	//     int ans = 0;
       	//     for (int i = 0; i < nums.size(); i++)
       	//     {
       	//         ans +=
       	//     }
       	// }
        int maximumCandies(vector<int> &nums, long long k)
        {
            int n = nums.size();
            int l = 1, r = *max_element(nums.begin(), nums.end());
            int ans = 0;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                long long cur = 0;
                for (int i = 0; i < n; i++)
                {
                    cur += (nums[i] / mid);
                }
                if (cur >= k)
                {
                    ans=mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            return ans;
        }
};