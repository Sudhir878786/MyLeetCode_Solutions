//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int func(int i,int j,int prev,int a[],vector<vector<int>>&dp)
    {
        if(i==j){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take=0+func(i+1,j,prev,a,dp);
        int no=0;
        if(prev==-1 || a[i]>a[prev]){
            no=1+func(i+1,j,i,a,dp);
        }
        return dp[i][prev+1]=max(no,take);
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return func(0,n,-1,a,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends