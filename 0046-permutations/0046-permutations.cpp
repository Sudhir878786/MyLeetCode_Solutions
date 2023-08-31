class Solution {
public:
    vector<vector<int>>ans;
    void func(vector<int>&nums,int ind)
    {
        if(ind==nums.size()){
            ans.push_back(nums);
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            func(nums,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<int>&cur;
        func(nums,0);
        
        return ans;
    }
};