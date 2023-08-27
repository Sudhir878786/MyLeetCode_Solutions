class Solution {
public:
    
    int find(int ind,vector<int>&nums,int tar,vector<int>&dp)
    {
        if(ind==nums.size()-1)
        {
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int ans=INT_MIN;
        
        for(int i=ind+1;i<nums.size();i++)
        {
            if(abs(nums[i]-nums[ind])<=tar) //checking  if we can jump to i
            {
                ans=max(ans,1+find(i,nums,tar,dp)); // jump to i 
            }
        }
        return  dp[ind] = ans;
    }
    int maximumJumps(vector<int>& nums, int tar)
    {
       vector<int>dp(nums.size()+1,-1);
        int ans=find(0,nums,tar,dp);
       if(ans>0)
           return ans;
        else
            return -1;
    }
};