class Solution {
public:
    // hame wo particular point find krna h jisse dono ocean m ja rha ho  
    void dfs_pac(vector<vector<int>>& heights,vector<vector<bool>>&pac,vector<vector<bool>>&atl,int n,int m,int i,int j)
    {
        pac[i][j]=true;
        if(i-1>=0 and pac[i-1][j]!=true and heights[i-1][j]>=heights[i][j]){
            dfs_pac(heights,pac,atl,n,m,i-1,j);
        }
        if(i+1<n and pac[i+1][j]!=true and heights[i+1][j]>=heights[i][j]){
            dfs_pac(heights,pac,atl,n,m,i+1,j);
        }
        if(j-1>=0 and pac[i][j-1]!=true  and heights[i][j-1]>=heights[i][j]){
            dfs_pac(heights,pac,atl,n,m,i,j-1);
        }
        if(j+1<m and pac[i][j+1]!=true  and heights[i][j+1]>=heights[i][j]){
            dfs_pac(heights,pac,atl,n,m,i,j+1);
        }
        
        
        
    }
       void dfs_atl(vector<vector<int>>& heights,vector<vector<bool>>&pac,vector<vector<bool>>&atl,int n,int m,int i,int j)
    {
        atl[i][j]=true;
        if(i-1>=0 and atl[i-1][j]!=true and heights[i-1][j]>=heights[i][j]){
            dfs_atl(heights,pac,atl,n,m,i-1,j);
        }
        if(i+1<n and atl[i+1][j]!=true and heights[i+1][j]>=heights[i][j]){
            dfs_atl(heights,pac,atl,n,m,i+1,j);
        }
        if(j-1>=0 and atl[i][j-1]!=true  and heights[i][j-1]>=heights[i][j]){
            dfs_atl(heights,pac,atl,n,m,i,j-1);
        }
        if(j+1<m and atl[i][j+1]!=true  and heights[i][j+1]>=heights[i][j]){
            dfs_atl(heights,pac,atl,n,m,i,j+1);
        }
        
        
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pac(n,vector<bool>(m,false));   //  dono ocean k liye vis bna liya
        vector<vector<bool>>atl(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            dfs_pac(heights,pac,atl,n,m,i,0);
            dfs_atl(heights,pac,atl,n,m,i,m-1);
        }
        for(int j=0;j<m;j++){
            dfs_pac(heights,pac,atl,n,m,0,j);
            dfs_atl(heights,pac,atl,n,m,n-1,j);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] and atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};