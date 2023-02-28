//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

	public:
	int mod = 1e9+7;
	int solve(int i, int sum, int n, int arr[], vector<vector<int>>&dp){
	    if(i == n){
	        if(sum == 0) return 1;
	        return 0;
	    }
	    if(dp[i][sum] != -1) return (dp[i][sum])%mod;
	    
	    int pick = 0, notPick = 0;
	    notPick = solve(i+1, sum, n, arr, dp);
	    if(arr[i] <= sum)
	        pick = solve(i+1, sum-arr[i], n, arr, dp);
	        
	    return dp[i][sum] = (pick + notPick)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return solve(0, sum, n, arr, dp)%mod;
	}
	  
};

	  

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends