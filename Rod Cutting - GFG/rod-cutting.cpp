//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int func(int n, int len,int price[],vector<vector<int>>&dp)
    {
        if(n==0){
            return len*price[0];
        }
        
        // if(n<0)return 1e9;
        if(dp[n][len]!=-1)return dp[n][len];
        int dpic=func(n-1,len,price,dp);
        int p=INT_MIN;
        int l=n+1;
        if(l<=len){
            p=price[n]+func(n,len-l,price,dp);
        }
        return dp[n][len]= max(p,dpic);
        
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return func(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends