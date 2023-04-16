class Solution {
public:
    void func(vector<int>&nums,int j,vector<vector<int>>&ans)
    {
        if(j==nums.size()){
            ans.push_back(nums);

        }
        for(int i=j;i<nums.size();i++){
            swap(nums[j],nums[i]);
            func(nums,j+1,ans);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        func(nums,0,ans);
        
        return ans;
    }
};