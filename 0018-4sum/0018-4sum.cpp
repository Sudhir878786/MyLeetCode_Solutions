class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            vector<vector < int>> ans;
            int n = nums.size();
            sort(nums.begin(), nums.end());
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
                    int k = j + 1;
                    int s = n - 1;
                    while (k < s)
                    {
                        if ((long long) nums[i] + (long long) nums[j] + (long long) nums[k] + (long long) nums[s] == target)
                        {
                            ans.push_back({ nums[i],
                                nums[j],
                                nums[k],
                                nums[s] });
                            while (k < s and nums[k] == nums[k + 1])
                            {
                               	// continue;
                                k++;
                            }
                            while (k < s and nums[s] == nums[s - 1])
                            {
                               	// continue;
                                s--;
                            }
                            k++;
                            s--;
                        }
                        else if ((long long) nums[i] + (long long) nums[j] + (long long) nums[k] + (long long) nums[s] < target)
                        {
                            k++;
                        }
                        else s--;
                    }
                }
            }
            return ans;
        }
};