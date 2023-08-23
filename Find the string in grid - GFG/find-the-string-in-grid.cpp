//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    int s=word.size();
	    set<vector<int>>st;
	    vector<int>dx={-1,0,1,0,-1,1,1,-1},dy={0,1,0, -1,-1,1,-1,1};
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(word[0]!=grid[i][j]){
	                continue;
	            }
	            // if match
	            for(int x=0;x<8;x++){
	                int next=1;
	                int r=i+dx[x];
	                int c=j+dy[x];
	                while(next<s and r>=0 and r<n and c<m and c>=0 and grid[r][c]==word[next])
	                {
	                    r+=dx[x];
	                    c+=dy[x];
	                    next++;
	                }
	                if(next==s)
	                {
	                    st.insert({i,j});
	                }
	            }
	        }
	    }
	    vector<vector<int>>ans(st.begin(),st.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends