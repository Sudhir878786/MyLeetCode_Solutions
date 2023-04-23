class Solution {
public:
   int mod = 1e9+7;
    int solve(string &str,int &k,vector<int> &dp,int &n,int s){
        if(s==n)return 1;
        if(str[s]=='0')return 0;
        if(dp[s] != -1)return dp[s];
        long int y = 0,x = 0;
        for(int i = s; i < n; i++){
            if(x*10+(str[i]-'0')<=k){
                x = x*10+(str[i]-'0');
                y = (y+solve(str,k,dp,n,i+1))%mod;
            }else{
                break;
            }
        }
        return dp[s] = y;
    }
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return solve(s,k,dp,n,0);
    }
};