class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int idx = i + questions[i][1] + 1;
            if (idx < questions.size()) {
                dp[i] = dp[idx] + questions[i][0];
            } else {
                dp[i] = questions[i][0];
            }
            if (i < questions.size() - 1) {
                dp[i] = max(dp[i + 1], dp[i]);
            }
        }
        return dp[0];
        }

};