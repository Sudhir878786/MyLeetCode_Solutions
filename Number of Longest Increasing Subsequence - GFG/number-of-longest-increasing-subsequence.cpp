//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        // int n=arr.size();
        vector<int>dp(n+1,1);
        int ans=0;
        vector<int>count(n+1,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[prev]<arr[i] and 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    count[i]=count[prev];
                }
                else if(arr[prev]<arr[i] and 1+dp[prev]==dp[i]){
                    count[i]+=count[prev];
                }
            }
            ans=max(ans,dp[i]);
        }
        int cur=0;
        for(int i=0;i<n;i++){
            
            if(dp[i]==ans){
                cur+=count[i];
            }
        }
        return cur;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends