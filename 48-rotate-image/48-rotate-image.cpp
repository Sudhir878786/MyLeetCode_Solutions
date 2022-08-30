class Solution {
public:
  
    void rotate(vector<vector<int>>& v) {
        int n = v.size();
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                swap(v[i][j],v[n-1-i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(v[i][j],v[j][i]);
            }
        }
    }
};