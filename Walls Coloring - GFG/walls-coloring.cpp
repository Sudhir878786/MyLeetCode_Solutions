//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int func(int i,vector<vector<int>>&colors,int last,vector<vector<int>>&dp)
    {
        if(i==0){
            int cur=INT_MAX;
            for(int j=0;j<3;j++){
                if(last!=j){
                    cur=min(cur,colors[i][j]);
                }
            }
            return cur;
        }
        if(dp[i][last]!=-1){
            return dp[i][last];
        }
        int ans=INT_MAX;
        for(int j=0;j<3;j++){
            if(last!=j){
                int cost=colors[i][j]+func(i-1,colors,j,dp);
                ans=min(ans,cost);
            }
        }
        return dp[i][last]= ans;
    }
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<vector<int>>dp(N+1,vector<int>(3+1,-1));
        return func(N-1,colors,3,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends