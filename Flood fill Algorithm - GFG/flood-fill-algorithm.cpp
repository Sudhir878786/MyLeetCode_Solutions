//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void  dfs(vector<vector<int>>& grid, int sr, int sc, int neww,int old)
    {
        if(sr>=grid.size()|| sc>=grid[0].size()|| sr<0 || sc<0 || grid[sr][sc]!=old){
            return ;
        }
        grid[sr][sc]=neww;
        dfs(grid,sr+1,sc,neww,old);
        dfs(grid,sr-1,sc,neww,old);
        dfs(grid,sr,sc+1,neww,old);
        dfs(grid,sr,sc-1,neww,old);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int neww) {
        // Code here 
        int n=grid.size();
        int m=grid[0].size();
        if(grid[sr][sc]!=neww){
            dfs(grid,sr,sc,neww,grid[sr][sc]);
        }
        return grid;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends