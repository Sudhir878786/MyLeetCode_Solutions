class Solution {
public:
    int func(vector<int>&arr,int d,int ind,vector<int>&dp)
    {
        
        int ans=1;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int n=arr.size();
        for(int i=ind+1;i<=min(ind+d,n-1) and arr[ind]>arr[i];i++){
            ans=max(ans,1+func(arr,d,i,dp));
        }
        for(int i=ind-1;i>=max(ind-d,0) and arr[ind]>arr[i];i--){
            ans=max(ans,1+func(arr,d,i,dp));
        }
        return dp[ind]= ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        int ans=1;
        vector<int>dp(n+1,-1);
        for(int i=0;i<n;i++){
            ans=max(ans,func(arr,d,i,dp));
        }
        return ans;
    }
};