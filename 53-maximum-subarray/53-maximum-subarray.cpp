class Solution {
public:
   int maxSubArray(vector<int>& nums) {
       
       int n = nums.size();
       int cursum=nums[0];
       int ans=nums[0];
       for(int i=1;i<n;i++){
           cursum=max(cursum+nums[i],nums[i]);
           ans=max(ans,cursum);
       }
       return ans;
        
       
    }
};