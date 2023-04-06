//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int n, vector<int> &arr) {
        // code here
         int low = 0;
    int high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int leftSum = 0;
        int rightSum = 0;
        for(int i = 0; i < mid; i++) {
            leftSum += arr[i];
        }
        for(int i = mid+1; i < n; i++) {
            rightSum += arr[i];
        }
        if(leftSum == rightSum) {
            return mid+1;
        }
        else if(leftSum < rightSum) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends