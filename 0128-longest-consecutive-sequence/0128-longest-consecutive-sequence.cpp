class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());	// sort array
            int longest = 1;
            int current = 1;
            if(nums.size()==0)return 0;
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] == nums[i - 1]) continue;	// skip if num has already been visited
                if (nums[i] == nums[i - 1] + 1)
                {
                    current++;
                }
                else
                {
                    longest = max(longest, current);
                    current = 1;
                }
            }
            return max(longest, current);
        }
};