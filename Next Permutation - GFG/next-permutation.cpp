//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        vector<int>ans;
        int pi=-1;
        for(int i =N-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                pi=i;
                break;
            }
        }
        for(int i=N-1;i>=pi;i--){
            if(pi!=-1){
                if(arr[i]>arr[pi]){
                    swap(arr[i],arr[pi]);
                    break;
                }
            }
            
        }
        reverse(arr.begin()+pi+1,arr.end());
        for(auto it:arr){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends