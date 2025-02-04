class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));  // Initialize visited matrix
        int freshCount = 0;

        // Initialize queue with rotten oranges & count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // Directions for moving up, right, down, left
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        int time = 0, rottenCount = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check boundaries & fresh orange condition
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;  // Mark as rotten
                    rottenCount++;
                }
            }
        }

        // If not all fresh oranges are rotten
        return (rottenCount == freshCount) ? time : -1;
    }
};
