//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int dp[100001][2][5];
int solve(int i, int n, int buy, int cnt, vector<int>& price)
{
    if(i>=n)
    {
        return 0;
    }
    if(cnt==0)
    {
        return 0;
    }
    if(dp[i][buy][cnt] != -1)
    {
        return dp[i][buy][cnt];
    }
    
    if(buy==1)
    {
        return dp[i][buy][cnt] = max(solve(i+1, n, 1, cnt, price) , -price[i]+solve(i+1, n, 0, cnt-1, price));
    }
    else
    {
        return dp[i][buy][cnt] = max(solve(i+1, n, 0, cnt, price) , price[i]+solve(i+1, n, 1, cnt-1, price));
    }
}
int maxProfit(vector<int>&price)
{
    memset(dp, -1, sizeof(dp));
    return solve(0, price.size(), 1, 4, price);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends