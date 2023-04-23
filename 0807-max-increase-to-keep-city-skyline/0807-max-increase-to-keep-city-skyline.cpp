class Solution
{
    public:
        int maxIncreaseKeepingSkyline(vector<vector < int>> &grid)
        {
            int n = grid.size();
            vector<int> maxRow(n, 0);	// Max height for each row
            vector<int> maxCol(n, 0);	// Max height for each column

           	// Find max height for each row and column
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    maxRow[i] = max(maxRow[i], grid[i][j]);
                    maxCol[j] = max(maxCol[j], grid[i][j]);
                }
            }
           	// cout<<endl;
            int totalIncrease = 0;	// Total increase in building heights

           	// Calculate the total increase in building heights
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                   	// The increase in height should be the minimum of the max height for row and column minus the current height
                    int increase = min(maxRow[i], maxCol[j]) - grid[i][j];
                    totalIncrease += increase;
                }
            }

            return totalIncrease;
        }
};