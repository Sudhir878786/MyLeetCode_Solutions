//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isboard(int i, int j,int n,int m)
    {
        return (i==0 || j==0 || i==n-1 || j==m-1);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        // int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isboard(i,j,n,m) and grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int xdir[]={-1,0,1,0};
        int ydir[]={0,1,0,-1};
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r=xdir[i]+cur.first;
                int c=ydir[i]+cur.second;
                if(r>=0 and c>=0 and r<n and c<m and vis[r][c]==0 and grid[r][c]==1)
                {
                    q.push({r,c});
                    vis[r][c]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and vis[i][j]==0){
                    ans++;
                }
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends