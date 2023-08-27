class Solution {
public:
    vector<vector<int>>ans;

    void func(int ind,vector<int>&nums,vector<int>cur)
    {
        if(ind==nums.size()){
           ans.push_back(cur);
            return;
        }
        func(ind+1,nums,cur);
        cur.push_back(nums[ind]);
        func(ind+1,nums,cur);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        func(0,nums,cur);
        return ans;
    }
};