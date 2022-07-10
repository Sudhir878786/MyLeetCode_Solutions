// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
  vector<vector<int>>ans;
   void solve(vector<vector<int>> &grid,int n,int m, vector<int>&v,int i,int j){
       if(i==n and j==m){
           v.push_back(grid[i][j]);
           ans.push_back(v);
           v.pop_back();
           return;
       }
       if(i<0 || j<0 || i>n||j>m){
           return;
       }
       v.push_back(grid[i][j]);
       solve(grid,n,m,v,i+1,j);
       solve(grid,n,m,v,i,j+1);
       v.pop_back();
   }



    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<int>v;
        solve(grid,n-1,m-1,v,0,0);
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends