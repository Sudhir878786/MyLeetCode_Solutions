class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=0;
        int minn=nums[0];
        int diff=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>minn){
                diff=max(diff,nums[i]-minn);
                
            }else{
                minn=nums[i];
            }
        }
        return diff;
    }
};