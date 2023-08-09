class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>res;
        vector<vector<int>>ans(n+2,vector<int>(m+2,-1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans[i][j]=mat[i-1][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(ans[i][j]>ans[i-1][j] and ans[i][j]>ans[i+1][j] and ans[i][j]>ans[i][j-1] and ans[i][j]>ans[i][j+1]){
                    res.push_back(i-1);
                    res.push_back(j-1);
                    return res;
                    
                }
            }
            
        }
        return res;
    }
};