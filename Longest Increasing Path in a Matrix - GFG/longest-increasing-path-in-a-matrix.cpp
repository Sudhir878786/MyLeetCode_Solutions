//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
vector<vector<int>>dp; 

   int solve(int x, int y, int prev, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& visited){

       if(x<0 || x>=n || y<0 || y>=m ||visited[x][y]==1 ||matrix[x][y]<=prev){

           return 0;

       }

       if(dp[x][y] != -1){

           return dp[x][y];

       }

       visited[x][y]=1;

       int ans =0;

       int a = solve(x+1, y, matrix[x][y], matrix, n, m, visited);

       int b = solve(x-1, y, matrix[x][y], matrix, n, m, visited);

       int c = solve(x, y+1, matrix[x][y], matrix, n, m, visited);

       int d = solve(x, y-1, matrix[x][y], matrix, n, m, visited);

       ans = 1+ max(a, max(b, max(c, d)));

       visited[x][y]=0;

       return dp[x][y] = ans;

       

   }

   int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {

       dp.resize(n,vector<int>(m,-1));

       int ans = 0;

       vector<vector<int>>visited(n, vector<int>(m, 0));

       for(int i=0;i<n;i++){

           for(int j=0;j<m;j++){

               ans = max(ans, solve(i, j, -1, matrix, n, m, visited));

           }

       }

       return ans;

   }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends