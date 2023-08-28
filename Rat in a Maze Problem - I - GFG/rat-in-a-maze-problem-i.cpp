//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(int i, int j,int n,vector<vector<int>> vis,string s,vector<string> &ans,vector<vector<int>> &m)
    {
        if(i<0 || i>=n || j<0 || j>=n || vis[i][j]==1 || m[i][j]==0)
        return ;
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            return;
        }
   
        
            vis[i][j]=1;
            dfs(i+1,j,n,vis,s+"D",ans,m);
            dfs(i,j+1,n,vis,s+"R",ans,m);
            dfs(i-1,j,n,vis,s+"U",ans,m);
            dfs(i,j-1,n,vis,s+"L",ans,m);
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<string> ans;
        dfs(0,0,n,vis,"",ans,m);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends