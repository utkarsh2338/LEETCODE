class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int cnt = 0; // Count of zeros
        int ans = 0;

        while (j < n) {
            if (nums[j] == 0) {
                cnt++;
            }

            if (cnt > 1) { // More than one zero is not allowed
                if (nums[i] == 0)
                    cnt--;
                i++;
            }

            ans = max(ans, j - i); // Maximum valid subarray length
            j++;
        }

        return ans;
    }
};
