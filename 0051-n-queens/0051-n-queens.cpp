class Solution {
public:
    // bool isSafe(vector<string>& board, int row, int col, int n) {

    //     // Check upper cells in same column
    //     for (int i = row - 1; i >= 0; i--) {
    //         if (board[i][col] == 'Q')
    //             return false;
    //     }

    //     int i = row - 1;
    //     int j = col + 1;

    //     while (i >= 0 && j < n) {

    //         if (board[i][j] == 'Q')
    //             return false;

    //         i--;
    //         j++;
    //     }

    //      i = row - 1;
    //      j = col - 1;

    //     while (i >= 0 && j >= 0) {

    //         if (board[i][j] == 'Q')
    //             return false;

    //         i--;
    //         j--;
    //     }

    //     return true;
    // }
    void solve(vector<string> board, vector<vector<string>>& ans, int row,
               int n, unordered_set<int>& cols, unordered_set<int>& diag,
               unordered_set<int>& antiDiag) {
        if (row >= n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int diagConstant = row + col;
            int antiDiagConstant = row - col;
            if (cols.find(col) != cols.end() ||
                diag.find(diagConstant) != diag.end() ||
                antiDiag.find(antiDiagConstant) != antiDiag.end()) {
                continue;
            }
            cols.insert(col);
            diag.insert(diagConstant);
            antiDiag.insert(antiDiagConstant);
            board[row][col] = 'Q';
            solve(board, ans, row + 1, n, cols, diag, antiDiag);
            cols.erase(col);
            diag.erase(diagConstant);
            antiDiag.erase(antiDiagConstant);
            board[row][col] = '.';

            // // check is safe
            // if (isSafe(board, row, col, n)) {
            //     board[row][col] = 'Q';
            //     solve(board, ans, row + 1, n);
            //     board[row][col] = '.';
            // }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> cols;
        unordered_set<int> diag;
        unordered_set<int> antiDiag;
        solve(board, ans, 0, n, cols, diag, antiDiag);
        return ans;
    }
};