class Solution {
public:
    vector<vector<string>>ans;

    bool isSafe(int row, int col, vector<string>& board, int n) {

        // Check upper-left diagonal
        int r = row, c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        // Check same column
        r = row;
        while (r >= 0) {
            if (board[r][col] == 'Q')
                return false;
            r--;
        }

        // Check upper-right diagonal
        r = row;
        c = col;
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c++;
        }

        return true;
    }

    void solve(int row, vector<string>& board, int n) {

        // Base Case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column in the current row
        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, board, n)) {

                // Place Queen
                board[row][col] = 'Q';

                // Solve for next row
                solve(row + 1, board, n);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(0, board, n);

        return ans;
    }
};