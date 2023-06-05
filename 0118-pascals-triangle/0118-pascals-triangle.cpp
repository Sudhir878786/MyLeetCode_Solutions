class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> x(numRows);
        x[0].push_back(1);
        for(int i=1;i<numRows;i++){
            x[i].push_back(1);
            for(int j=0;j<x[i-1].size()-1;j++){
                int d=x[i-1][j] + x[i-1][j+1];
                x[i].push_back(d);
            }
            
            x[i].push_back(1);
                
        }
        return x;
    }
};