class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum = 0;
                for(int p = max(0,i-k);p<=min(n-1,i+k);p++){
                    for(int q=max(0,j-k);q<=min(m-1,j+k);q++){
                        sum += mat[p][q];
                    }
                }
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};