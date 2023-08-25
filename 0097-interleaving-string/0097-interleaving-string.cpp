class Solution {
public:
    bool func(string &s1, string &s2, string &s3,int i,int j,int k,int n,int m,int c,vector<vector<int>>&dp)
    {
        if(i==n and j==m and k==c){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool x=0,y=0;
        if(i!=n)
        {
            if(s1[i]==s3[k]){
                x=func(s1,s2,s3,i+1,j,k+1,n,m,c,dp);
            }
        }
        if(j!=m){
            if(s2[j]==s3[k]){
                y=func(s1,s2,s3,i,j+1,k+1,n,m,c,dp);
            }
        }
        return dp[i][j] = x||y;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int c=s3.size();
        if((m+n)!=c){
            return false;
        }
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(s1,s2,s3,0,0,0,n,m,c,dp);
    }
};