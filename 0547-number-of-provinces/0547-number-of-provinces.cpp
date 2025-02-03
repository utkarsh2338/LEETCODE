class Solution {
public:
    void dfs(int node,vector<vector<int>>& adjLs,vector<int>& visited){
            visited[node] = 1;
            for(auto& it: adjLs[node]){
                if(!visited[it]){
                    dfs(it,adjLs,visited);
                }
            }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // no. of rows
        // let's make our adjacency list
        vector<vector<int>> adjLs(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int countProvince = 0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                countProvince++;
                dfs(i,adjLs,visited);
            }
        }
        return countProvince;
    }
};