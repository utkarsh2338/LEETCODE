class Solution {
public:
    bool isSafe(vector<string>& board, int n, int x, int y) {
        // checking the attack from the upper side of the queen toh isliye col
        // toh same hi rahega bas jo change hoga vo hoga hamra row is liye
        // [row][y]
        for (int row = 0; row < n; row++) {
            if (board[row][y] == 'Q') {
                return false;
            }
        }
        // checking the above diagonal on the left side
        int row = x;
        int col = y;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        // checking the diagonal on the right side
        row = x;
        col = y;
        while (row >= 0 && col < n) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col++;
        }
        return true;
    }
    // writing the recursive function
    void solve(vector<vector<string>>& ans, vector<string>& board, int n,
               int row) {
        if (row >= n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, n, row, col)) {
                board[row][col] =
                    'Q'; // yaha par mai kuchh kar rha hu is liye "Do"
                solve(ans, board, n,
                      row + 1); // yaha apr ham kya kar rhe ki explore kar rhe
                                // hain isliye "Explore"
                board[row][col] = '.'; // is jagah par undo ho rha yani ki back
                                       // tracking ham laga rhe hain
            }
        }
    }
    // here is my main function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(ans, board, n, 0);
        return ans;
    }
};