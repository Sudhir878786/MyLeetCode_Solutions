class Solution {
public:
    int ans=0;
    int emp=1;
    void dfs(int i,int j,vector<vector<int>>&grid,int n,int m,int count)
    {
        if(i>=n || j>=m|| i<0 || j<0 || grid[i][j]==-1){
            return ;
        }
        if(grid[i][j]==2){
            if(emp==count){
                ans++;
                
            }
            return;
        }
        grid[i][j]=-1;
        
        dfs(i+1,j,grid,n,m,count+1);
        dfs(i-1,j,grid,n,m,count+1);
        dfs(i,j+1,grid,n,m,count+1);
        dfs(i,j-1,grid,n,m,count+1);
        
        grid[i][j]=0;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int s=0,e=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    s=i;
                    e=j;
                    
                }
                else if(grid[i][j]==0)emp++;
            }
        }
        dfs(s,e,grid,n,m,0);
        
        return ans;
        
        
        
    }
};