class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans(0);
        vector<unordered_map<long ,long>>dp(nums.size());
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long long diff=(long long)(nums[i])-(long long)(nums[j]);
                dp[i][diff]++;
                if(dp[j].count(diff)){
                    dp[i][diff]+=dp[j][diff];
                    ans+=dp[j][diff];
                }
            }
        }
        return ans;
    }
};