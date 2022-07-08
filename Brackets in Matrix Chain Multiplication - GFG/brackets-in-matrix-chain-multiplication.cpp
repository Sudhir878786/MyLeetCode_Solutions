// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

   struct Details{
    int cost;
    string chain;
    
    Details(int cost, string chain):  cost(cost), chain(chain) {}
};

class Solution{
    Details *dp[27][27];
public:

    Details *rec(int i, int j, int p[]){
        if(i == j){
            string curr = "";
            curr += ('A'+i-1);
            return new Details(0, curr);
        }
        if(dp[i][j]->chain != "")   return dp[i][j];
        
        int min_cost = INT_MAX;
        string chain = "";
        for(int k=i;k<j;k++){
            Details *left = rec(i, k, p);
            Details *right = rec(k+1, j, p);
            
            int curr_cost = (p[i-1] * p[k] * p[j]) + left->cost + right->cost;
            
            if(min_cost > curr_cost){
                chain = "(" + left->chain + right->chain + ")";
                min_cost = curr_cost;
            }
        }
        return dp[i][j] = new Details(min_cost, chain);
    }
    
    string matrixChainOrder(int p[], int n){
        // code here
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = new Details(0, "");
            }
        }
        return rec(1, n-1, p)->chain;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends