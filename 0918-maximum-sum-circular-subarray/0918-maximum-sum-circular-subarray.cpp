class Solution
{
    public:
        int maxSubarraySumCircular(vector<int> &nums)
        {
            int max_sum = INT_MIN, min_sum = INT_MAX, curr_max = 0, curr_min = 0, total = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                curr_max = max(nums[i], curr_max + nums[i]);
                max_sum = max(max_sum, curr_max);
                curr_min = min(nums[i], curr_min + nums[i]);
                min_sum = min(min_sum, curr_min);
                total += nums[i];
            }
            return max_sum > 0 ? max(max_sum, total - min_sum) : max_sum;
        }
};