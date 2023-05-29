class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
           int matrix[m][n]; //mxn matrix
        for(int i=0;i<m;i++){ //initializing every element as 0
            for(int j=0;j<n;j++){
                matrix[i][j] = 0;
             }
        }
        
        //increment operation as per the description
        for(int i=0;i<indices.size();i++){
            int row = indices[i][0];
            int col = indices[i][1];
            
            for(int j=0;j<n;j++){
                matrix[row][j]++;
            }
            for(int j=0;j<m;j++){
                matrix[j][col]++;
            }
        }
        //printing the modified matrix
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        //checking for odd numbers in O(m*n)
        int numberOdd = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]%2!=0){
                    numberOdd++;
                }
            }
        }
        return numberOdd;
    }
};