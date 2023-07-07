//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    vector<string>ans;
	    map<string,int>mp;
	    void func(int i,int j,string s,string t,string cur,int len)
	    {
	        if(len==0){
	            reverse(cur.begin(),cur.end());
	            if(mp.find(cur)==mp.end()){
	                ans.push_back(cur);
	                mp[cur]++;
	            }
	            return;
	            
	        }
	        if(i==0 || j==0){
	            return ;
	        }
	        for(int row=i;row>0;row--){
	            for(int col=j;col>0;col--){
	                if(s[row-1]==t[col-1]){
	                    cur+=s[row-1];
	                    func(row-1,col-1,s,t,cur,len-1);
	                    cur.pop_back();
	                }
	            }
	        }
	    }
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    int n=s.length();
	    int m=t.length();
	    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
            func(s.size(),t.size(),s,t,"",dp[s.size()][t.size()]);
            sort(ans.begin(),ans.end());
            return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends