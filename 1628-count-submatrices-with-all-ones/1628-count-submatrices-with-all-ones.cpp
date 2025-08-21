class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();    // rows
        int m = mat[0].size(); // cols
        int ans = 0;
        vector<int> height(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                height[j] = mat[i][j] ? height[j] + 1 : 0;
            }

            vector<int> sum(m, 0);
            stack<int> st;
            for (int j = 0; j < m; j++) {
                while (!st.empty() && height[st.top()] >= height[j])
                    st.pop();
                if (!st.empty()) {
                    int p = st.top();
                    sum[j] = sum[p] + height[j] * (j - p);
                } else {
                    sum[j] = height[j] * (j + 1);
                }
                st.push(j);
                ans += sum[j];
            }
        }
        return ans;
    }
};