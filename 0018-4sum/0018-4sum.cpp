class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            vector<vector < int>> ans;
            sort(nums.begin(), nums.end());
            int n = nums.size();
            for (int i = 0; i < n - 3; i++)
            {
                if (i > 0 and nums[i] == nums[i - 1])
                {
                    continue;
                }
                for (int j = i + 1; j < n - 2; j++)
                {
                    if (j > i + 1 and nums[j] == nums[j - 1])
                    {
                        continue;
                    }
                    int left = j + 1;
                    int right = n - 1;
                    while (left < right)
                    {
                        long long sum = (long long)nums[i] + (long long)nums[j] +(long long) nums[left] + (long long)nums[right];
                        if (sum == target)
                        {
                            ans.push_back({ nums[i],
                                nums[j],
                                nums[left],
                                nums[right] });
                            while (left < right and nums[left] == nums[left + 1])
                            {
                                left++;
                            }
                            while (left < right and nums[right] == nums[right - 1])
                            {
                                right--;
                            }
                            left++;
                            right--;
                        }
                        else if (sum < target)
                        {
                            left++;
                        }
                        else
                        {
                            right--;
                        }
                    }
                }
            }
            return ans;
        }
};