//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int func(int n,int w,int val[],int wt[],vector<vector<int>>&dp){
        if(n==0)return (w/wt[0])*val[0];
        if(dp[n][w]!=-1)return dp[n][w];
        int nott=func(n-1,w,val,wt,dp);
        int take=0;
        if(w>=wt[n]){
            take=val[n]+func(n,w-wt[n],val,wt,dp);
        }
        return dp[n][w]=max(take,nott);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        return  func(N-1,W, val, wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends