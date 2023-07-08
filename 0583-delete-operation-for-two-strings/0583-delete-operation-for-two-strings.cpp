class Solution
{
    public:
       	// intitution is  
       	// lets think of maximum number of step rewq to make both equal;
       	// which is lenght ofword1+word2;
       	// now finding the  lenght of longest commmon subseq 
       	// and subracting them form both the string lenght and add them

        int minDistance(string word1, string word2)
        {
            int n=word1.size();
            int m=word2.size();
            vector<vector<int>>dp(n+1,vector<int>(m+1,0));
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(word1[i-1]==word2[j-1]){
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else{
                        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    }
                }
            }
            return (n-dp[n][m])+(m-dp[n][m]);
        }
};