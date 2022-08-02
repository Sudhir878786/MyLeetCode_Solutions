class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>st(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                st[i*n+j]=matrix[i][j];
            }
        }
        sort(st.begin(),st.end());
        return st[k-1];
    }
};