// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool solve(string s1, string s2, string s3,int i,int j,int k,vector<vector<int>>&dp,int m,int n,int c)
   {
     if(dp[i][j]!=-1) return dp[i][j];
     if(i==m and j==n and k==c)return true;
     bool x=false,y=false;
     // case 1
     if(i!=m){
       if(s1[i]==s3[k]){
         x=solve(s1,s2,s3,i+1,j,k+1,dp,m,n,c);
       }
     }
     //case 2
     if(j!=n){
       if(s2[j]==s3[k]){
         y=solve(s1,s2,s3,i,j+1,k+1,dp,m,n,c);
       }
     }
     return dp[i][j]=x||y;  // if any one of x or y is true return true;
   }
    bool isInterleave(string s1, string s2, string s3) 
    {
        int m = s1.size(), n = s2.size(), c = s3.size();
        if (m + n != c) return false; // s3 length should be equal to size of s1,s2;
        int i,j,k=0;   // 3 pointer for s1,s2,s2;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));// dp table 
       
        return solve(s1,s2,s3,0,0,0,dp,m,n,c);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends