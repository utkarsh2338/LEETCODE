
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size(); // Number of queries
        int h = heights.size(); // Number of buildings
        
        vector<int> ans(n, -1);
        vector<vector<pair<int, int>>> storeQueries(h);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            
            if (a < b && heights[a] < heights[b]) {
                ans[i] = b;
            } else if (a > b && heights[a] > heights[b]) {
                ans[i] = a;
            } else if (a == b) {
                ans[i] = a;
            } else {
                storeQueries[max(a, b)].emplace_back(max(heights[a], heights[b]), i);
            }
        }

        for (int i = 0; i < h; i++) {
            while (!pq.empty() && pq.top().first < heights[i]) {
                ans[pq.top().second] = i;
                pq.pop();
            }

            for (auto& query : storeQueries[i]) {
                pq.push(query);
            }
        }

        return ans;
    }
};