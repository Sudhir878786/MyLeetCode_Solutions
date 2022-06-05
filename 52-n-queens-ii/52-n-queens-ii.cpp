class Solution {
public:
    int totalNQueens(int n) {
        vector < string > board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        return dfs(0, board);
    }
    int dfs(int col, vector < string > & board) {
      if (col == board.size()) {
        return 1;
      }
      int count = 0;
      for (int row = 0; row < board.size(); row++) {
        if (isSafe(row, col, board)) {
          board[row][col] = 'Q';
          count += dfs(col + 1, board);
          board[row][col] = '.';
        }
      }
      return count;
    }
    bool isSafe(int row, int col, vector < string > board) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < board.size() && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }
};