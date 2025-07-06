class Solution {
public:
    vector<vector<int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();    // no. of rows
        int n = maze[0].size(); // no. of cols

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int level = 0;
        while (!q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                pair<int, int> temp = q.front();
                q.pop();

                // if (temp == make_pair(entrance[0], entrance[1]))
                //     return -1;

                int i = temp.first, j = temp.second;
                if ((temp != make_pair(entrance[0], entrance[1])) &&
                    (i == 0 || i == m - 1 || j == 0 || j == n - 1))
                    return level;
                // explore neighbours
                for(auto& dir: directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && maze[new_i][new_j] != '+'){
                        q.push(make_pair(new_i,new_j));
                        maze[new_i][new_j] = '+';
                    }
                }
            }
            level++;
        }
        return -1;
    }
};