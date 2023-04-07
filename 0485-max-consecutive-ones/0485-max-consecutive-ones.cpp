class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ans++;
            }
            else{
                ans=0;
            }
            count=max(ans,count);
        }
        return count;
    }
};