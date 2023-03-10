//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                vis[i][j]=1;
	                q.push({{i,j},0});
	            }
	            else vis[i][j]=0;
	        }
	    }
	    int xdir[]={-1,0,1,0};
	    int ydir[]={0,1,0,-1};
	    while(!q.empty()){
	        auto cur=q.front();
	        int row=cur.first.first;
	        int col=cur.first.second;
	        int step=cur.second;
	        q.pop();
	        dist[row][col]=step;
	        for(int i=0;i<4;i++){
	            int r=xdir[i]+row;
	            int c=ydir[i]+col;
	            if(r>=0 and c>=0 and r<n and c<m  and vis[r][c]==0){
	                
	                    vis[r][c]=1;
	                    q.push({{r,c},step+1});
	                }
	            }
	        }
	       // cout<<q.front().first<<q.front().second<<endl;
	    
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends