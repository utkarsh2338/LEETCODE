class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int idx = 0;
        int m = target.size();

        for (int i = 1; i <= n && idx < m; i++) {
            res.push_back("Push");
            if (i == target[idx]) {
                idx++;        // Correct element, keep it
            } else {
                res.push_back("Pop"); // Remove unwanted element
            }
        }
        return res;
    }
};
