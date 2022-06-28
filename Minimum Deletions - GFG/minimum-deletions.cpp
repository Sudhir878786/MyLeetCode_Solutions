// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        // code here
        if(s.size()==0 || s.size()==1) return 0;
        int dp[1000][1000]={0};
        string a=s;
        int n = s.size();
        reverse(a.begin(),a.end());
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=s.size();j++)
            {
                if(s[i-1]==a[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return n-dp[n][n];
    } 
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}  // } Driver Code Ends