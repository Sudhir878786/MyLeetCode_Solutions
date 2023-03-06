//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        vector<int>ans;
        sort(arr.begin(),arr.end());
        vector<int>hash(n+1);
        vector<int>dp(n+1,1);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 and 1+dp[prev]>dp[i])
                {
                  dp[i]=1+dp[prev];
                  hash[i]=prev;
                }
            }
        }
        int cur=-1;
        int last=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>cur){
                cur=dp[i];
                last=i;
            }
        }
        ans.push_back(arr[last]);
        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(arr[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends