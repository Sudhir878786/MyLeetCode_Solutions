//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int func(int x,int y,vector<vector<int>> &Matrix,vector<vector<int>> &dp)

    {

        if(x<0 or x>=Matrix.size() or y<0 or y>=Matrix[0].size())

        {

            return 0;

        }

        if(x==Matrix.size()-1)

        {

            return Matrix[x][y];

        }

        if(dp[x][y] != -1)

        {

            return dp[x][y];

        }

        return dp[x][y] = Matrix[x][y] + max({func(x+1,y,Matrix,dp),func(x+1,y-1,Matrix,dp),func(x+1,y+1,Matrix,dp)});

    }

    int maximumPath(int N, vector<vector<int>> Matrix)

    {

      vector<vector<int>> dp(N,vector<int>(N,-1));

      int ans = 0;

      for(int i = 0;i<Matrix[0].size();i++)

      {

          ans = max(ans,func(0,i,Matrix,dp));

      }

      return ans;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends