class Solution {
public:
/*
Firstly take the transpose and then reverse each of the rows.
how to take the transpose--> we can see that the diagonal element in the transpose remains the same and the other elements are just swapped
i.e., matrix[i][j] and matrix[j][i] they are just the swapped values */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose the matrix
        // time complexity -> O(n/2*n/2)
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {// yaha par i+1 se chalna imp h
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // time complexity-> O(n*n/2) for reverse the time complexity is n/2 by two pointer approach
        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
