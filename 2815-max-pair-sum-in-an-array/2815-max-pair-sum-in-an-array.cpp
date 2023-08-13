class Solution {
public:
    int func(int num) {
        int mx = 0;
        while (num > 0) {
            mx = max(mx, num % 10);
            num /= 10;
        }
        return mx;
    }
    int maxSum(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(func(nums[i])==func(nums[j])){
                    ans=max(ans,nums[i]+nums[j]);
                }
            }
        }
        return ans;
    }
};