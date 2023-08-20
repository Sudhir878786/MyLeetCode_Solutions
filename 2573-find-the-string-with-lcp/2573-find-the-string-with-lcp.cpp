class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string ans="";
        for(int i=0;i<n;i++){
            ans+='a';
        }
        // if lcp[i][j]==0 that  means word[i]!=word[j];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(lcp[i][j]==0 and ans[i]==ans[j]){
                    ans[j]++;
                }
            }
        }
        // if any char in ans is > z return ""
        for(auto it:ans){
            if(it>'z'){
                return "";
            }
        }
        // we gonna create our ownn dp or own  lcp matrix and compare with the given one if ! match ""; else ans
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(ans[i]==ans[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
            }
        }
        // compare
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]!=lcp[i][j]){
                    return "";
                }
            }
        }
        return ans;
    }
};