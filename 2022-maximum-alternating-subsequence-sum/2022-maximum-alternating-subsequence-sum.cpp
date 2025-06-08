// Recursion + Memoizationn approach using 2D dp
#define ll long long
class Solution {
public:
    ll solve(ll idx, bool flag,vector<int>& nums,vector<vector<ll>>& dp){
        int n = nums.size();
        if(idx >= n){
            return 0;
        }
        if(dp[idx][flag] != -1){
            return dp[idx][flag];
        }
        ll not_take = solve(idx+1,flag,nums,dp);
        ll val = nums[idx];
        if(flag == false){
            val = -val;
        }
        ll take = val + solve(idx+1,!flag,nums,dp);
        return dp[idx][flag] = max(take,not_take);
    }
    ll maxAlternatingSum(vector<int>& nums) {
        ll n = nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));
        return solve(0,true,nums,dp);
    }
};