class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int j=0;
        int zero=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
            }
            while(zero>1){
                if(nums[j]==0){
                    zero--;
                }
                j++;
            }
            ans=max(ans,i-j+1-zero);
        }
        if(ans==nums.size()){
            return ans-1;
        }
        return ans;
    }
};