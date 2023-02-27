//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int func(int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 || j==0)return 1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int l=func(i-1,j,dp);
        int r=func(i,j-1,dp);
        return dp[i][j]=l+r;
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
        return func(a-1,b-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends