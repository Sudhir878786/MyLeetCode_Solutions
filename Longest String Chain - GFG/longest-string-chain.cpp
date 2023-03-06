//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool comp(string &a,string &b){
      if(a.size()-b.size()!=1)return false;
      int i=0;
      int j=0;
      while(i<a.size()){
          if(j<b.size() and a[i]==b[j]){
              i++;j++;
              
          }else
          {
              i++;
          }
      }
      if(i==a.size() and j==b.size()){
          return true;
      }
      else return false;
  }
  bool static c(string&a,string&b){
      return a.size()<b.size();
  }
    int longestChain(int n, vector<string>& w) {
        // Code here
        int ans=0;
        sort(w.begin(),w.end(),c);
        vector<int>dp(n+1,1);
        for(int i=0;i<n;i++){
            for(int p=0;p<i;p++){
                if(comp(w[i],w[p]) and 1+dp[p]>dp[i]){
                    dp[i]=1+dp[p];
                }
            }
            ans=max(ans,dp[i]);
        }
        
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends