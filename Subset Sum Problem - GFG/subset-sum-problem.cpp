//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int func(int i,vector<int>&arr,int sum,vector<vector<int>>&dp)
    {
        if(i==arr.size()){
            if(sum==0)return 1;
            else return 0;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int pick=0,notpick=0;
        if(arr[i]<=sum){
            pick=func(i+1,arr,sum-arr[i],dp);
        }
        notpick=func(i+1,arr,sum,dp);
        return dp[i][sum]= pick+notpick;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return func(0,arr,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends