class Solution {
public:
    
    int LCS(string s,string str)
    {
        int n=s.size(),m=str.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==str[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
    int LPS(string s){
        string str=s;
        reverse(str.begin(),str.end());
        return LCS(s,str);
    }
    
    int minInsertions(string s) {
        return s.size()-LPS(s);
    }
};