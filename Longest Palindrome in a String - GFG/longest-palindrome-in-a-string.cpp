//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n=S.size();
        int start=0,end=1;
        for(int i=0;i<n;i++){
            int l=i-1;
            int h=i;
            while(l>=0 and h<n and S[l]==S[h]){
                if(h-l+1>end){
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
                
            }
            l=i-1;
            h=i+1;
            while(l>=0 and h<n and S[l]==S[h]){
                if(h-l+1>end){
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
                
            }
        }
        string ans=S.substr(start,end);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends