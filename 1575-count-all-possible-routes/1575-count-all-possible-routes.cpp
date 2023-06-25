class Solution {
public:
    int func(vector<int>& locations, int start, int finish, int fuel,int n,vector<vector<int>>&dp)
    {
        if(fuel<0){
            return 0;
        }
        if(dp[start][fuel]!=-1){
            return dp[start][fuel];
        }
        int ans=0;
        if(start==finish){
            ans++;
        }
        
        for(int i=0;i<n;i++){
            if(i!=start){
                ans=(ans%1000000007+ func(locations,i,finish,fuel-abs(locations[i]-locations[start]),n,dp))%1000000007;
            }
        }
        return dp[start][fuel]= ans%1000000007;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>>dp(n+1,vector<int>(fuel+1,-1));
        return func(locations,start,finish,fuel,n,dp);
    }
};