//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int func(int coins[],int sum,int ind,int M,vector<vector<int>>&dp){
	    if(ind==M|| sum<0){
	        return 1e8;
	    }
	  
	    if(sum==0){
	        return 0;
	    }
	    if(dp[ind][sum]!=-1){
	        return dp[ind][sum];
	    }
	
	    int p=1+func(coins,sum-coins[ind],ind,M,dp);
	    int q=func(coins,sum,ind+1,M,dp);
	    
	    return dp[ind][sum]= min(p,q);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    if(func(coins,V,0,M,dp)>=1e8){
	        return -1;
	    }
	   
	    return func(coins,V,0,M,dp);
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends