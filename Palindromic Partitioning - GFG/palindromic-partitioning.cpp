//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool ispal(int i,int j,string&s)
    {
        while(i<j){
            if(s[i++]!=s[j--]){
                return 0;
            }
        }
        return 1;
    }
    int func(int i,int j,string& str,vector<int>&dp)
    {
        if(i==j)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            if(ispal(i,k ,str)){
                int cur=1+func(k+1,j,str,dp);
                ans=min(ans,cur);
            }
        }
        return dp[i]=ans;
        }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int>dp(n+1,-1);
        return func(0,n,str,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends