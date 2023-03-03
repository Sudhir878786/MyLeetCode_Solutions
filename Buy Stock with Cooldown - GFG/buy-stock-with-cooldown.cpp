//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// ong long maximumProfit(vector<long long>&p, int n) {

class Solution{

    public:

    long long solve(int idx, int buy, vector<long long> &prices, vector<vector<long long>> &dp){

        if(idx >= prices.size()){

            return 0;

        }

        if(dp[idx][buy] != -1){

            return dp[idx][buy];

        }

        int profit = 0;

        if(buy){

            profit = max(-prices[idx] + solve(idx+1, 0, prices, dp), 0 + solve(idx+1, 1, prices, dp));

        }else{

            profit = max(prices[idx] + solve(idx+2, 1, prices, dp), 0 + solve(idx+1, 0, prices, dp));

        }

        return dp[idx][buy] = profit;

    }

    long long maximumProfit(vector<long long>&prices, int n) {

        // Code here

        vector<vector<long long >> dp(n, vector<long long>(2, -1));

        return solve(0, 1, prices, dp);

    }

};
   

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends