class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size()+1,1);
        vector<int>hash(nums.size()+1);
        for(int i=0;i<nums.size();i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 and 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                    
                }
            }
        }
        int cur=-1;
        int last=-1;
        for(int i=0;i<nums.size();i++){
            if(dp[i]>cur){
                cur=dp[i];
                last=i;
            }
        }
        ans.push_back(nums[last]);
        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(nums[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};