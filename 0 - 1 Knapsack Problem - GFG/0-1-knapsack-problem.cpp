//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int func(int n,int W,int wt[],int val[],vector<vector<int>>&dp)
    {
        if(n==0){
            if(wt[n]<=W){
                return val[n];
            }
            return 0;
        }
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        int ans=INT_MIN;
        int mis=func(n-1,W,wt,val,dp);
        int hit=0;
        if(wt[n]<=W){
            hit=val[n]+func(n-1,W-wt[n],wt,val,dp);
        }
        return dp[n][W] = max(hit,mis);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return func(n-1,W,wt,val,dp);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends