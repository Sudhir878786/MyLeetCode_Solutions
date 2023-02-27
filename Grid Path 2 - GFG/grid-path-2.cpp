//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int ans=0;
  int mod = 1e9+7;
        int dfs(int i,int j,vector<vector<int>>&grid,int n,int m,vector<vector<int>>&dp)
        
    {
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==1){
            return 0;
        }
        if(i==n-1 and j==m-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
       int a= dfs(i+1,j,grid,n,m, dp)%mod;
       int b= dfs(i,j+1,grid,n,m,dp)%mod;;
        ans=a+b;
        return dp[i][j]=ans%mod;;
    }

    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
    //   int n=grid.size();
    //     int ans=0;
    //     int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(grid[0][0]!=1){
           return dfs(0,0,grid,n,m,dp);
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends