class Solution {
public:
    int func(int i,vector<int>&nums,int tar)
    {
        if(tar==0 and i==nums.size()){
            return 1;
        }
        else if(i>=nums.size()) return 0;
        return func(i+1,nums,tar-nums[i])+func(i+1,nums,tar+nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return func(0,nums,target);
    }
};