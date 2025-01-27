class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, int src, int dst,
             vector<bool>& visited) {
        visited[src] = true;
        if (src == dst)
            return true;

        bool isReachable = false;
        for (auto& adjNode : adj[src]) {
            if (!visited[adjNode]) {
                isReachable = isReachable || dfs(adj, adjNode, dst, visited);
            }
        }
        return isReachable;
    }
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        int Q = queries.size();
        vector<bool> result(Q);
        for (int i = 0; i < Q; i++) {
            int u = queries[i][0]; // source
            int v = queries[i][1]; // destination
            vector<bool> visited(numCourses, false);
            result[i] = dfs(adj, u, v, visited);
        }
        return result;
    }
};