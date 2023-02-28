//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  bool func(int n,int sum,int arr[],vector<vector<int>>&dp){
      if(n==0)return dp[n][sum]=arr[n]==sum;
      if(sum==0) return dp[n][sum]=true;
      if(dp[n][sum]!=-1){
          return dp[n][sum];
      }
      int nottake=func(n-1,sum,arr,dp);
      int take=0;
      if(arr[n]<=sum){
          take=func(n-1,sum-arr[n],arr,dp);
      }
      return dp[n][sum]=take||nottake;
      
      }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        
	    }
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	    for(int i=0;i<=sum;i++){
	       bool f= func(n-1,i,arr,dp);
	    }
	    int ans=INT_MAX;
	    for(int i=0;i<=sum;i++){
	        if(dp[n-1][i]==true){
	            ans=min(ans,abs((i-(sum-i))));
	        }
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends