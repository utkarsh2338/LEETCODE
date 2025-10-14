
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (2 * k > n) return false;  
        for (int i = 0; i <= n - 2 * k; i++) {
            bool firstIncreasing = true;
            bool secondIncreasing = true;

            for (int j = 1; j < k; j++) {
                if (nums[i + j] <= nums[i + j - 1]) {
                    firstIncreasing = false;
                    break;
                }
            }

            if (firstIncreasing) {
                for (int j = 1; j < k; j++) {
                    if (nums[i + k + j] <= nums[i + k + j - 1]) {
                        secondIncreasing = false;
                        break;
                    }
                }
                if (secondIncreasing) {
                    return true;
                }
            }
        }
        return false;  
    }
};


