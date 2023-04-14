//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        int ans=0;
       for (int i = 0; i < n-1; i++) {
        if (color[i] == color[i+1] && radius[i] == radius[i+1]) {
            color.erase(color.begin() + i, color.begin() + i + 2);
            radius.erase(radius.begin() + i, radius.begin() + i + 2);
            n -= 2;
            i = max(-1, i-2);
        }
    }
    return n;
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends