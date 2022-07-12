// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
/* For substring of S starting from index 0 find the minimum length of uncommon sequence between substring and every substring of T

 

DP state 

if matching character is not found then answer is 1

if matching character is found then answer will be…

dp[i][j] will denote length of minimum uncommon sequence of S of first i chars and T of first j chars

dp[i][j] → S upto length i and T upto length j

 

Let's suppose string is 

S → upiu

T → pipu

 

S[0] ≠ T[0]

so dp[1][1] = 1 … considering 1 based indexing

 

S[0] ≠ T[1]

S[0] ≠ T[0]

dp[1][2] = 1

 

S[0] ≠ T[2]

S[0] ≠ T[1]

S[0] ≠ T[0]

dp[1][3] = 1

 

S[0] == T[4]

u

pipu

There is no uncommon subsequence possible…

 

now what ??? 

We have two choices for state dp[i][j]

We have to exclude the ith character and check upto given index j

i.e. dp[i][j] can be equal to dp[i-1][j]…

 

But suppose the first matching character was found at kth index so we are sure that length of uncommon sequence from k to j and string s of length i must be 1 right…

i.e. dp[i][j] can be equal to dp[i-1][k-1]+1*/

class Solution {
  public:
  // code here
      int shortestUnSub(string S, string T) {
    int n = S.size(), m = T.size();
    vector <vector<int>> dp(n+1, vector<int>(m+1, 1000));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int k = j;
            while(k && S[i-1] != T[k-1])
                k -= 1;
            if(k == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = min(dp[i-1][j], 1+dp[i-1][k-1]);
        }
    }
    return dp[n][m] == 1000 ? -1 : dp[n][m];
}
};
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends
