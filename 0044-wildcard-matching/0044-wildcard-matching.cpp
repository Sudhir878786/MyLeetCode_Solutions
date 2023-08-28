class Solution {
public:
    bool func(int i,int j,string &s,string &p,vector<vector<int>>&dp)
    {
        if(j>=p.size()){
            return i==s.size();
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool ans=0;
        if(s[i]==p[j]){
            ans|=func(i+1,j+1,s,p,dp);
        }
        else if(p[j]=='?'){
            ans|=func(i+1,j+1,s,p,dp);
        }
        else if(p[j]=='*'){
            ans|=func(i,j+1,s,p,dp);
            for(int ind=i;ind<s.size();ind++){
                ans|=func(ind+1,j+1,s,p,dp);
            }
        }
        return  dp[i][j]= ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+10,vector<int>(p.size()+10,-1));
        return func(0,0,s,p,dp);
    }
};