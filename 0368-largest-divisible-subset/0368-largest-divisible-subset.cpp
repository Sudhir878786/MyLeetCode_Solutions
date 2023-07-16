class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,1);
        vector<int>hash(n+1,1);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 and dp[i]<1+dp[prev])
                {
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
        }
        int ans=-1;
        int last=-1;
        for(int i=0;i<n;i++){
            if(ans<dp[i]){
                ans=dp[i];
                last=i;
            }
        }
        vector<int>res;
        res.push_back(nums[last]);
        while(hash[last]!=last){
            last=hash[last];
            res.push_back(nums[last]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};