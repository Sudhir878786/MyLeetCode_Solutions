//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int func(int i, int t,vector<int>&A)
    {
        if(i==A.size() and t==0){
            return 1;
        }
        if(i>=A.size())return 0;
        return func(i+1,t-A[i],A)+func(i+1,t+A[i],A);
    }
    int findTargetSumWays(vector<int>&A ,int t) {
        //Your code here
        return func(0, t,A); 
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends