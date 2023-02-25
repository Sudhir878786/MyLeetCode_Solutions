//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        if(n<0)return 1;
        vector<int>arr(n+1,0);
                int m=1e9+7;
            arr[0]=1;

        arr[1]=1;

        arr[2]=2;

        for(int i=3;i<=n;i++){

               //applying given condition

            arr[i]=(arr[i-1]%m + arr[i-2]%m)%m; 

        }

        return arr[n];

    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends