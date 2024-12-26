class Solution {
public:
    int n, result = 0;

    void solve(int idx, int sum, vector<int>& nums, int target) {
        // Base case
        if (idx == n) {
            if (sum == target) {
                result++;
            }
            return;
        }

        // Recursive calls for addition and subtraction
        solve(idx + 1, sum + nums[idx], nums, target);
        solve(idx + 1, sum - nums[idx], nums, target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        result = 0;  // Ensure result is reset for each function call
        solve(0, 0, nums, target);
        return result;
    }
};
