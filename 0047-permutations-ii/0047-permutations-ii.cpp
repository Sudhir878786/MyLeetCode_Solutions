class Solution
{
    public:
        set<vector < int>> ans;
    void permutation(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            ans.insert(nums);
       
        }

        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            permutation(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector < int>> permuteUnique(vector<int> &nums)
    {
        permutation(nums, 0);
        vector<vector < int>> res(ans.begin(), ans.end());
        return res;
    }
};