//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int ans=0;
        int cur=0;
        int reach=0;
        for(int i=0;i<n;i++){
            cur=max(cur,(i+arr[i]));
            if(i==reach){
                reach=cur;
                ans++;
                if(reach>=n-1){
                    return ans;
                }
            }
            
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends