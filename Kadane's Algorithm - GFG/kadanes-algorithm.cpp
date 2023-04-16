//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int nums[], int n){
        
    
    int max_sum = nums[0], curr_sum = nums[0];
    int max_start = 0, max_end = 0, curr_start = 0;
    for (int i = 1; i < n; i++) {
        if (curr_sum < 0) {
            curr_sum = nums[i];
            curr_start = i;
        } else {
            curr_sum += nums[i];
        }
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            max_start = curr_start;
            max_end = i;
        }
    }
    // cout << "Subarray with the largest sum: ";
    // for (int i = max_start; i <= max_end; i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    return max_sum;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends