// class Solution       MIN SUM PATH
// {
//     public:
//     //Function to return the minimum cost to react at bottom
// 	//right cell from top left cell.
// 	int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
// 	    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
// 	        return 1e5;
// 	    }
// 	    if(i==grid.size()-1 and j==grid[0].size()-1){
// 	       dp[i][j]= grid[i][j];
// 	    }
// 	    if(dp[i][j]!=-1){
// 	        return dp[i][j];
// 	    }
// 	    int down=grid[i][j]+ solve(grid,i+1,j,dp);
// 	    int right=grid[i][j]+ solve(grid,i,j+1,dp);
// 	    int up=grid[i][j]+ solve(grid,i-1,j,dp);
// 	    int left=grid[i][j]+ solve(grid,i,j-1,dp);
// 	    int a=min(left,right);
// 	    int b=min(down,up);
// 	    return  dp[i][j]= min(a,b);
// 	}
//     int minimumCostPath(vector<vector<int>>& grid) 
//     {
//         // Code here
//         vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
//         return solve(grid,0,0,dp);
//     }
// };
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
   {
       // Code here
       int n = grid.size();
       int m = n;
       set<pair<int,pair<int,int>>> store;
       store.insert({grid[0][0],{0,0}});
       vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
       vector<vector<int>> vis(n,vector<int>(n,0));
       int ans=0;
       while(store.empty()==false){
           pair<int,pair<int,int>> p = *(store.begin());
           store.erase(store.begin());
           int weight = p.first;
           
           int i=p.second.first;
           int j=p.second.second;
           vis[i][j]=1;
           
           if(j-1>=0 && vis[i][j-1]==0){
               if(dist[i][j-1] > weight + grid[i][j-1]){
                   dist[i][j-1] = weight + grid[i][j-1];
                   store.insert({dist[i][j-1],{i,j-1}});
                   vis[i][j-1]=true;
               }
           }
           if(j+1<m && vis[i][j+1]==0){
               if(dist[i][j+1] > weight + grid[i][j+1]){
                   dist[i][j+1] = weight + grid[i][j+1];
                   store.insert({dist[i][j+1],{i,j+1}});
                   vis[i][j+1]=true;
               }
           }
           if(i+1<n && vis[i+1][j]==0){
               if(dist[i+1][j] > weight + grid[i+1][j]){
                   dist[i+1][j] = weight + grid[i+1][j];
                   store.insert({dist[i+1][j],{i+1,j}});
                   vis[i+1][j]=true;
               }
           }
           if(i-1>=0 && vis[i-1][j]==0){
               if(dist[i-1][j] > weight + grid[i-1][j]){
                   dist[i-1][j] = weight + grid[i-1][j];
                   store.insert({dist[i-1][j],{i-1,j}});
                   vis[i-1][j]=true;
               }
           }
           
           
       }
       return dist[n-1][n-1];
       
   }
};
