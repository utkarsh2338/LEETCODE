class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& ans, vector<vector<int>>& image,
             int col, int delRow[], int delCol[], int iniColor) {
        ans[r][c] = col;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int neighRow = r + delRow[i];
            int neighCol = c + delCol[i];
            if (neighRow >= 0 && neighRow < n && neighCol >= 0 &&
                neighCol < m && image[neighRow][neighCol] == iniColor &&
                ans[neighRow][neighCol] != col) {
                dfs(neighRow, neighCol, ans, image, col, delRow, delCol,
                    iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, color, delRow, delCol, iniColor);
        return ans;
    }
};