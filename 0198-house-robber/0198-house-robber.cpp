// Recursion + memoisation approach 
class Solution {
public:
    int solve(int idx,vector<int>& nums,vector<int>& dp){
        // base case
        if(idx >= nums.size()){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int steal = nums[idx] + solve(idx+2,nums,dp);
        int skip = solve(idx+1,nums,dp);
        return dp[idx] = max(skip,steal);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};
// Initially I was using money also as a factor which was forcing me to make 2d dp which is not at all optimized in this case hence after removing money factor i was able to make the recursion and memoization process happen.