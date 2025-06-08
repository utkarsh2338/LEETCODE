class Solution {
public:
    int solve(int start, int end, vector<int>& dp, vector<int>& nums) {
        if (start > end) {
            return 0;
        }
        if (dp[start] != -1) {
            return dp[start];
        }
        int steal = nums[start] + solve(start + 2, end, dp, nums);
        int skip = solve(start + 1, end, dp, nums);
        return dp[start] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int max1 = solve(0, n - 2, dp1, nums); 
        int max2 = solve(1, n - 1, dp2, nums);

        return max(max1, max2);
    }
};
