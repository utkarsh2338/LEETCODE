class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<int> arr = nums;
        int n = arr.size();
        vector<long long> res(k, 0);
        vector<long long> dp(k, 0);

        for (int j = 0; j < n; j++) {
            int aj = arr[j] % k;
            vector<long long> new_dp(k, 0);
            new_dp[aj] += 1;
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int x = (int)((r * 1LL * aj) % k);
                    new_dp[x] += dp[r];
                }
            }
            for (int x = 0; x < k; ++x) {
                res[x] += new_dp[x];
            }
            dp.swap(new_dp);
        }

        return res;
    }
};