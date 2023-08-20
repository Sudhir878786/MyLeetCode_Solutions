class Solution {
public:
    
    // so here we can think of recurtion -- tkae not take 
    // or swap not swap   wchich will create dp[n][2];
    int func(vector<int>& nums1, vector<int>& nums2,int i,int prev1, int prev2,bool swap,vector<vector<int>>&dp)
    {
        if(i==nums1.size()){
            return 0;
        }
        if(dp[i][swap]!=-1){
            return dp[i][swap];
        }
        int ans=INT_MAX;
        
            if(nums1[i]>prev1 and nums2[i]>prev2){
                ans=min(ans,0+func(nums1,nums2,i+1,nums1[i],nums2[i],false,dp));
            }
        
       
            if(nums1[i]>prev2 and nums2[i]>prev1){
                ans=min(ans,1+func(nums1,nums2,i+1,nums2[i],nums1[i],true,dp));
            }
        
        return dp[i][swap]= ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(2+1,-1));
        return func(nums1,nums2,0,-1,-1,false,dp);
    }
};