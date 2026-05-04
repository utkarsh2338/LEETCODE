class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {// yaha par i+1 se chalna imp h
                swap(matrix[i][j], matrix[j][i]);
            }
        }    
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
