//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        // Code here
        // int n=nums.size();
        vector<int>dp(n+1,1),hash(n+1);
        vector<int>ans;
        // int ans=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int pre=0;pre<i;pre++){
                
                if(nums[i]>nums[pre] and 1+dp[pre]>dp[i]){
                    dp[i]=1+dp[pre];
                    hash[i]=pre;
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
        ans.push_back(nums[last]);
        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(nums[last]);
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends