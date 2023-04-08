//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int>a;
        stack<int>s;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(s.size()==0)s.push(arr[i]);
            else {
                int g=s.top();
                if((g>=0 && arr[i]>=0) || (g<0 && arr[i]<0)){
                   s.push(arr[i]); 
                }
                else s.pop();
            }
        }
        while(s.size()){
            a.push_back(s.top());
            s.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends