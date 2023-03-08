//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int func(int i,int n,int k,vector<int>&arr,vector<int>&dp)
    {
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int len=0;
        int maxi=INT_MIN;
        int sum=0;
        int ans=INT_MIN;
        for(int j=i;j<min(i+k,n);j++){
            len++;
            maxi=max(maxi,arr[j]);
            sum=len*maxi+func(j+1,n,k,arr,dp);
            ans=max(ans,sum);
        }
        return dp[i]=ans;
    }
    int solve(int n, int k, vector<int>& arr){
        // Code here
        vector<int>dp(n+1,-1);
        return func(0,n,k,arr,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends