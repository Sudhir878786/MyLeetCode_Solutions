class Solution {
public:
    int targetSum(vector<int>& nums, int i, int target)
    {
        if(target == 0 && i == nums.size())
            return 1;
        
        if(i >= nums.size())
            return 0;
        
        return targetSum(nums, i + 1, target - nums[i]) +
               targetSum(nums, i + 1, target + nums[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return targetSum(nums, 0, target);
    } 
};