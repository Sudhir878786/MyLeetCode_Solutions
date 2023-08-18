class Solution {
public:
    int func(vector<int>&nums,int i,int j,int win,vector<int>&pref,vector<vector<int>>&dp)
    {
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k=k+(win-1)){  // baki k dekh rhe 
            int cost= func(nums,i,k,win,pref,dp)+func(nums,k+1,j,win,pref,dp);
            ans=min(ans,cost);
        }
        // curr ans if  k the j-i==k-1;
        if((j-i)%(win-1)==0){
            ans+=pref[j+1]-pref[i];
            // return ans;
        }
        return dp[i][j]= ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        vector<int>pref(n+1,0);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        pref[0]=0;
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+stones[i-1];
            // cout<<pref[i]<<endl;
        }
        if((n-1)%(k-1)!=0){
            return -1;
        }
       
        return func(stones,0,n-1,k,pref,dp);

    }
};