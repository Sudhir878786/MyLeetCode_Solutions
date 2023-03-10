//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool issafe(int i,int j,int n,int m)
    {
        return (i>0 and j>0 and i<n and j<m);
    }
    bool isend(int i,int j,int n,int m)
    {
        return (i==0 || j==0 || i==n-1 ||j==m-1);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isend(i,j,n,m) and mat[i][j]=='O'){
                    mat[i][j]='#';
                    q.push({i,j});
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
                if( issafe(r,c,n,m) and !isend(r,c,n,m) and mat[r][c]=='O'){
                    mat[r][c]='#';
                    q.push({r,c});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O'){
                    mat[i][j]='X';
                }
                else if(mat[i][j]=='#'){
                    mat[i][j]='O';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends