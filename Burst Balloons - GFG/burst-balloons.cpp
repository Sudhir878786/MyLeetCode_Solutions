//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxCoins(int n, vector<int> &arr) {
        // code here
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,0));
        for(int i=arr.size()-3;i>=0;i--){
            for(int j=i+2;j<arr.size();j++){
                for(int k=i+1;k<j;k++){
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[j]*arr[k]);
                    // cout<<dp[i][j]<<endl;
                }
            }
            
        }
        return dp[0][arr.size()-1];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends