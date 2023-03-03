//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string str1, string str2, int n, int m)
    {
        //code here
        
        int lcs=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            
        }
        int i=n;
        int j=m;
        string ans="";
        while(i>=1 and j>=1){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;j--;
            }
            else if(dp[i-1][j]<dp[i][j-1]){
                ans+=str2[j-1];
                j--;
            }
            else{
                ans+=str1[i-1];
                i--;
            }
        }
        while(i>=1){
            ans+=str1[i-1];i--;
        }
        while(j>=1){
            ans+=str2[j-1];j--;
        }
        reverse(ans.begin(),ans.end());
        return ans.size();
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends