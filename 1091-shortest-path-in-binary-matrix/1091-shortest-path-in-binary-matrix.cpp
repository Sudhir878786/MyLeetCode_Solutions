/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
public:
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == n-1 && y == m-1) return grid[x][y];
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <=1; j++) {
                    if (i == 0 && j == 0) continue;
                    int nx = x + i;
                    int ny = y + j;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 0) continue;
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
        
    }
};