//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
  int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int mxsum=INT_MIN,mxsum2=INT_MIN;
        int t_sum=0,t_sum2=0;
        for(int i=0;i<n;i++){
            int tempsum=0;
            int tempsum2=0;
            for(int j=0;j<n;j++){
                tempsum+=matrix[i][j];//curr row sum
                tempsum2+=matrix[j][i];//curr col sum
            }
            t_sum+=tempsum;//total row sum
            t_sum2+=tempsum2;//total col sum
            mxsum=max(tempsum,mxsum);//maximum row sum
            mxsum2=max(tempsum2,mxsum2);//maximum col sum
        }

//finally return depending upon max of mxrowsum or mxcolsum.
        if(mxsum2>mxsum)
        return n*mxsum2-t_sum2;
        return n*mxsum-t_sum;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends