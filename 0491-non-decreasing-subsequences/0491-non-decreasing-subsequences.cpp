class Solution
{
    public:
      void dfs(vector<int>& nums, vector<int>& sub, vector<vector<int>> &ans, int start) {
    if (sub.size() >= 2) ans.push_back(sub);
    unordered_set<int> used;
    for (int i = start; i < nums.size(); i++) {
        if (used.count(nums[i]) || (sub.size() && nums[i] < sub.back())) continue;
        used.insert(nums[i]);
        sub.push_back(nums[i]);
        dfs(nums, sub, ans, i + 1);
        sub.pop_back();
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> sub;
    dfs(nums, sub, ans, 0);
    return ans;

        }
};