//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int f(int ind,int pre_ind,int n,int arr[],vector<vector<int>>&dp)
    {
        if(ind==n)    
        {
            return 0;
        }
        
        if(dp[ind][pre_ind+1]!=-1)
          return dp[ind][pre_ind+1];
          
        int notTake=0+f(ind+1,pre_ind,n,arr,dp);
        int take=0;
        if(pre_ind==-1 || arr[ind]>arr[pre_ind])
        {
            take=arr[ind]+f(ind+1,ind,n,arr,dp);
        }
        return dp[ind][pre_ind+1]=max(take,notTake);
    }
    
    int maxSumIS(int arr[], int n)  
    {  
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,n,arr,dp);
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends