class Solution {
public:
    vector<vector<char>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool wordSearch(int i, int j, int idx, string& word,
                    vector<vector<char>>& board) {
        int m = board.size();    // no. of rows
        int n = board[0].size(); // no. of columns
        // base cases for the backtracking
        if (idx == word.length())
            return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') {
            return false;
        }
        if (board[i][j] != word[idx])
            return false;

        // backtracking se pahle usey mark bhi toh karna padega
        // storing the value of board[i][j] so that i can mark it again
        char temp = board[i][j];

        //  backtracking
        board[i][j] = '$'; // marked it visited

        // here the condition for 4 directions
        for (auto& it : directions) {
            int i_ = i + it[0];
            int j_ = j + it[1];

            if (wordSearch(i_, j_, idx + 1, word, board)) {
                return true;
            }
        }
        board[i][j] = temp;

        return false;
        // kabhi nahi mila toh ham kar denge isey return
    }
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();    // no. of rows
        int n = board[0].size(); // no. of columns
        // we'll go to each cell and call the function to check
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] &&
                    wordSearch(i, j, 0, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};