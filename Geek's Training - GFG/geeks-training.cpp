//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int  func(vector<vector<int>>&points,int days,int last,vector<vector<int>>&dp)
  {
      if(days==0){
          int maxi=0;
          for(int i=0;i<3;i++){
              if(i!=last){
                  maxi=max(maxi,points[0][i]);
              }
          }
          return maxi;
      }
      if(dp[days][last]!=-1)return dp[days][last];
      int ans=0;
      for(int i=0;i<3;i++){
          if(i!=last){
             int point=points[days][i]+func(points,days-1,i,dp);
             ans=max(ans,point);
          }
         
      }
      return  dp[days][last]= ans;
  }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(points.size()+1,vector<int>(4,-1));
        return func(points,n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends