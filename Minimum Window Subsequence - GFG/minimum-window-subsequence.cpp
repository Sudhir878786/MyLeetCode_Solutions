//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        int n1=str1.size();
        int n2=str2.size();
        if(n2>n1){
            return "";
        }
        int start=0,end=0,k=0,min_start;
        int ans=INT_MAX;
        while(end<n1 and k<n2){
            if(str1[end]==str2[k]){
                k++;
            }
            if(k==n2){
                start=end;
                k=n2-1;
                while(start>=0 and k>=0){
                    if(str1[start]==str2[k]){
                        k--;
                    }
                    start--;
                }
                start++;
                if(end-start+1<ans)
                {
                    ans=end-start+1;
                    min_start=start;
                }
                k=0;
                end=start+1;
            }
            end++;
        
        }
        if(ans!=INT_MAX){
            return str1.substr(start,ans);
        }
        return "";
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends