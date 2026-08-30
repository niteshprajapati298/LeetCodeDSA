class Solution {
public:
    bool isValid(int row, int col, vector<string>& board) {
        // check the cols && rows
         int n = board[0].size();
          // Same column
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
        int i = row - 1;
        int j = col - 1;

        // left upper diagonal
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                cout << "Returnni false b2 " << endl;
                return false;
            }
            i--;
            j--;
        }
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') {
                cout << "Returnni false b3 " << endl;

                return false;
            }
            j++;
            i--;
        }

        // right upper diagonal

        return true;
    }

    void solve(int& n, int row, vector<string>& board,
               vector<vector<string>>& ans) {

        if (row >= n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            bool canPlace = isValid(row, col, board);
            cout << " canPlace " << canPlace << endl;
            if (canPlace) {
                // check valid hai ya nahi
                board[row][col] = 'Q';

                // next ke liye check karo
                solve(n, row+1, board, ans);

                // revert back all the shells
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        int row = 0;
        solve(n, row, board, ans);
        return ans;
    }
};