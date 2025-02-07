// class Solution {
// public:
//     vector<int> queryResults(int limit, vector<vector<int>>& queries) {
//         int n = queries.size();// rows
//         int m = queries[0].size();//cols
//         unordered_map<int,int>mpp;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 mpp[queries[i][j]]++;
//             }
//         }
//         vector<int>ans;
//         for(int i=1;i<=limit;i++){
//             ans.push_back(mpp[i]);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorMap, ballMap;

        // Iterate through queries
        for (int i = 0; i < n; i++) {
            // Extract ball label and color from query
            int ball = queries[i][0], color = queries[i][1];

            // Check if ball is already covered
            if (ballMap.find(ball) != ballMap.end()) {
                // Decrement count of the previous color on the ball
                int prevColor = ballMap[ball];
                colorMap[prevColor]--;

                // If there are no balls with previous color left, remove color
                // from color map
                if (colorMap[prevColor] == 0) colorMap.erase(prevColor);
            }
            // Set color of ball to the new color
            ballMap[ball] = color;

            // Increment the count of the new color
            colorMap[color]++;

            result[i] = colorMap.size();
        }

        return result;
    }
};