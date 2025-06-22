class Solution {
public:
    vector<int> findCoins(const vector<int>& numWays) {
        int N = numWays.size();
        vector<long long> dp(N+1, 0);
        dp[0] = 1;
        vector<int> coins;
        
        for (int i = 1; i <= N; ++i) {
            int target = numWays[i-1];
            if (dp[i] == (long long)target - 1) {
                coins.push_back(i);
                for (int j = i; j <= N; ++j) {
                    dp[j] += dp[j - i];
                }
            }
            if (dp[i] != target) {
                return {};
            }
        }
        
        return coins;
    }
};