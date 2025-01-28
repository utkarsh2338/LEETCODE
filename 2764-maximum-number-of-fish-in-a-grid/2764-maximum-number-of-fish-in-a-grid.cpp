class Solution {
public:
    int m,n;
    vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};// left right down up (LRDU)
    int dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0){
            return 0;
        }

        int fishCount = grid[i][j];
        grid[i][j] = 0;// took the fish from this cell
        for(vector<int>dir: dirs){
            int i_ = i+ dir[0];
            int j_ = j+ dir[1];

            fishCount += dfs(i_,j_,grid);
        }
        return fishCount;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();// no. of rows
        n = grid[0].size(); // no. of columns
        int maxFish = 0;
        // fisher man ko mujhe har ek cell me lekr jana hai
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(grid[i][j]>0){// mtlb hai ki usko ek water cell mil gaya hai
                // pickup the cell
                maxFish = max(maxFish,dfs(i,j,grid));
                 }
            }
        }
        return maxFish;
    }
};