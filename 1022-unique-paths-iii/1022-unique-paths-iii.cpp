class Solution {
public:
    int m, n;
    int ans;
    int nonObstacleCount;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    void nonObstacle(int i,int j,int count,vector<vector<int>>& grid){
        // base cases 
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == -1)
            return;
        if(grid[i][j] == 2){
            if(count==nonObstacleCount){
                ans++;
            }  
            return;
        }
        grid[i][j] = -1;
        for(auto& it: directions){
            int new_i = i+ it[0];
            int new_j = j+ it[1];
            nonObstacle(new_i,new_j,count+1,grid);
        }
        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();    // no. of rows
        n = grid[0].size(); // no. of cols
        ans = 0;
        nonObstacleCount =0;
        int start_x =0,start_y =0;  
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    nonObstacleCount++;
                }
                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j; 
                }
        }
    }
    nonObstacleCount++;
    int count =0;
    nonObstacle(start_x,start_y,count,grid); 
    return ans;
}
}
;