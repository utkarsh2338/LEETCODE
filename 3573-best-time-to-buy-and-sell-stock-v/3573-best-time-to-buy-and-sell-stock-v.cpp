class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if(n == 0 || k == 0) return 0;
        vector<vector<long long>>dp(k+1,vector<long long>(3,0));

        for(int i=0;i<=k;i++){
            dp[i][1] = INT_MIN;
            dp[i][1] = INT_MIN;
        }

        for(auto& it: prices){
            for(int i=k;i>=1;i--){
                dp[i][0] = max(dp[i][0],dp[i][1] + it);
                dp[i][0] = max(dp[i][0],dp[i][2] - it);

                dp[i][1] = max(dp[i][1],dp[i-1][0] - it);
                dp[i][2] = max(dp[i][2],dp[i-1][0] + it);
            }
        }

        long long maxProfit = 0;
        for(int i =0;i<=k;i++){
            maxProfit = max(maxProfit,dp[i][0]);
        }
        return maxProfit;
    }
};