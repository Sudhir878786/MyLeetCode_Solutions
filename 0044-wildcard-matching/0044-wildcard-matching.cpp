class Solution {
public:
    int f(int i,int j, string &s,string &p,vector<vector<int>> &dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) return dp[i][j]=1;
        if(j==0 && i>0) return dp[i][j]=0;
        if(i==0 && j>0)
        {
            while(j>0)
            {
                if(p[j-1]=='*') j--;
                else return dp[i][j]=0;
            }
            return dp[i][j]=1;
        }
        
        if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        
        if(p[j-1]=='*')
        {
            return dp[i][j] = f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp) ;
            //Two cases
            //Consider * as len=0
            //Give one charcter to * and remain at *
            //at next step it will again be decided from both these cases
        }
        return dp[i][j]=0;
        
    }
    
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
    }
};