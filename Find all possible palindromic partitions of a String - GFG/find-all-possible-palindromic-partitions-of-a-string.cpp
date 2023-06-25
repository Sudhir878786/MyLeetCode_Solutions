// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>>ans;
        vector<string>temp;
        solve(S,0,temp,ans);
        return ans;
    }
    
    void solve(string S, int ind, vector<string>& temp, vector<vector<string>>& ans){
        if(ind==S.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=ind;i<S.length();i++){
            if(ispal(S,ind,i)){
                temp.push_back(S.substr(ind,i+1-ind));
                solve(S,i+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    bool ispal(string S, int st, int end){
        while(st<=end){
            if(S[st++]!=S[end--]) return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends