//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int func(int i,int arr[],int sum,vector<vector<int>>&dp,int N)
    {
        if(i==N){
            if(sum==0){
                return 1;
            }
            else {
                return 0;
            }
            
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int nott=func(i+1,arr,sum,dp,N);
        int take=0;
        if(arr[i]<=sum){
            take=func(i+1,arr,sum-arr[i],dp,N);
        }
        dp[i][sum]=take+nott;
        
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
            
        }
        if(sum%2==1)return 0;
        
        
        else {
            sum=sum/2;
            vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
            return func(0,arr,sum,dp,N);
        }
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends