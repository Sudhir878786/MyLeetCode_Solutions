//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
   int solve(int i, int limit, vector<int>& a, vector<vector<int>> &dp)
    {
        if(i>=a.size())return 0;
        
        if(dp[i][limit] != -1)
            return dp[i][limit] ;
        
        if(limit){
            return dp[i][limit] = max(a[i] + solve(i+1, limit-1, a, dp) , solve(i+1, 2, a, dp));
        }
        else{
            return dp[i][limit]  = solve(i+1, 2, a, dp);
        }
    }
  int findMaxSum(vector<int>& a){
      //Code Here
      int  n=a.size();
      vector<vector<int>>dp(n,vector<int>(2+1,-1));
      return solve(0,2,a,dp);

  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends