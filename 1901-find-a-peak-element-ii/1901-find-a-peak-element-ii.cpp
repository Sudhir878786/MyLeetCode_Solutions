class Solution {
public:
   bool func(vector<vector<int>>& matrix, int row, int col) {

    int rows = matrix.size();

    int cols = matrix[0].size();

 

    vector<pair<int, int>> neighbors = {{row-1, col}, {row+1, col}, {row, col-1}, {row, col+1}};

    for (const auto& neighbor : neighbors) {

        int r = neighbor.first;

        int c = neighbor.second;

        if (r >= 0 && r < rows && c >= 0 && c < cols && matrix[r][c] > matrix[row][col])

            return false;

    }

    return true;

}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
//         vector<int>res;
//         vector<vector<int>>ans(n+2,vector<int>(m+2,-1));
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 ans[i][j]=mat[i-1][j-1];
//             }
//         }
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(ans[i][j]>ans[i-1][j] and ans[i][j]>ans[i+1][j] and ans[i][j]>ans[i][j-1] and ans[i][j]>ans[i][j+1]){
//                     res.push_back(i-1);
//                     res.push_back(j-1);
//                     return res;
                    
//                 }
//             }
            
//         }
//         return res;
        
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            int ind=max_element(mat[mid].begin(),mat[mid].end())-mat[mid].begin();
            if(func(mat,mid,ind)){
                return {mid,ind};
            }
            else if(mid>0 and mat[mid-1][ind]>mat[mid][ind] ){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return {-1,-1};
        
    }
};