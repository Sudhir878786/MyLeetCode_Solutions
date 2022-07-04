class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
      int n=str1.size();
      int m=str2.size();
      vector<vector<int>>dp(n+1,vector<int>(m+1,0));
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          if(str1[i-1]==str2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];  // LCS 
          }
          else {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
        }
      }
      
      int i=n,j=m;
      string s="";
      while(i>=1 and  j>=1){
        if(str1[i-1]==str2[j-1]){
          s+=str1[i-1];
          i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
          s+=str1[i-1];
          i--;
        }
        else {
          s+=str2[j-1];j--;
        }
      }
      while(i>0){
        s+=str1[i-1];i--;
      }
      while(j>0){
        s+=str2[j-1];j--;
      }
      reverse(s.begin(),s.end());
      return s;
        
    }
};