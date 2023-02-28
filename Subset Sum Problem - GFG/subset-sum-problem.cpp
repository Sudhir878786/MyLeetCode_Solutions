//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool func(int n,int sum,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(sum==0)return 1;
        if(n==0)return arr[0]==sum;
        if(dp[n][sum]!=-1)return dp[n][sum];
        int nott=func(n-1,sum,arr,dp);
        int take=0;
        if(sum>=arr[n]){
            take=func(n-1,sum-arr[n],arr,dp);
        }
        return dp[n][sum]= take||nott;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return func(arr.size()-1,sum,arr,dp);
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