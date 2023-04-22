class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_row_idx = 0; // index of row with max ones
    int max_ones = 0; // number of ones in the row with max ones

    // Iterate through each row in the matrix
    for (int i = 0; i < mat.size(); i++) {
        int row_ones = 0; // count number of ones in current row
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) {
                row_ones++;
            }
        }

        // Update max_row_idx and max_ones if current row has more ones
        if (row_ones > max_ones) {
            max_row_idx = i;
            max_ones = row_ones;
        }
    }

    // Create and return the result array
    vector<int> result = {max_row_idx, max_ones};
    return result;
    }
};