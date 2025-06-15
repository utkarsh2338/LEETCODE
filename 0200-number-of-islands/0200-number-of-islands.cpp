class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m) {
        vis[i][j] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int newRow = i + drow[k];
            int newCol = j + dcol[k];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                dfs(newRow, newCol, grid, vis, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, vis, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
