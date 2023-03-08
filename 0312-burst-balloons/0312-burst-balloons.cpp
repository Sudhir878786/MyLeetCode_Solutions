class Solution {
public:
//     int func(int i,int j,vector<int>&nums)
//     {
//         if(i>j)return 0;
//         int ans=INT_MIN;
//         for(int ind=i;ind<j;ind++){
//             int cur=nums[i-1]*nums[i]*nums[i+1]+func(i,ind,nums)+func(ind+1,j,nums);
//             ans=min(ans,cur);
            
//         }
//         return ans;
//     }
    int maxCoins(vector<int>& nums) {
      
        nums.push_back(1);
        nums.insert(nums.begin(),1);
          int n=nums.size();
        // return func(1,n,nums);
        vector<vector<int>>dp(n,vector<int>(n,0));
        // int ans=/INT_MIN;
        for(int i=n-3;i>=0;i--){
            for(int j=i+2;j<n;j++){
                for(int k=i+1;k<j;k++){
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+nums[j]*nums[i]*nums[k]);
                    // cout<<dp[i][j]<<endl;
                }
            }
            
        }
        return dp[0][n-1];
        
    }
};