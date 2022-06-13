class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        vector<int> temp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    temp.push_back(i);
                    temp.push_back(j);
                }
            }
        }
        
        for(int i=0;i<temp.size();i+=2){
            for(int k=0;k<n;k++){
                matrix[temp[i]][k]=0;
            }

            for(int l=0;l<m;l++){
                matrix[l][temp[i+1]]=0;
                
            }
        }
         
        
    }
};