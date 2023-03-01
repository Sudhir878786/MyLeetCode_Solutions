//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int func(int n,int tot,int wt[],int val[],vector<vector<int>>&dp)
    {
        if(n==0){
            if(wt[n]<=tot){
                return val[0];
            }
            else return 0;
        }
        if(dp[n][tot]!=-1)return dp[n][tot];
        int nott=0+func(n-1,tot,wt,val,dp);
        int take=INT_MIN;
        if(wt[n]<=tot){
            take=val[n]+func(n-1,tot-wt[n],wt,val,dp);
        }
        dp[n][tot]=max(take,nott);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return func(n-1, W,wt, val,dp);
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