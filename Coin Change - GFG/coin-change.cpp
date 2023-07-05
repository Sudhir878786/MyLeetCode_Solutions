//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long func(int n,int coins[],int sum ,vector<vector<  long long>>&dp)
    {
        if(n==0){
            return sum%coins[0]==0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
          long long nott=0+func(n-1,coins,sum,dp);
          long long take=0;
        if(sum>=coins[n]){
            take=func(n,coins,sum-coins[n],dp);
        }
        return dp[n][sum]=take+nott;
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long>>dp(N+1,vector<  long long>(sum+1,-1));
        return func(N-1,coins,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends