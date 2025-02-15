class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            bool isGood = true;
            
            if (i - k >= 0 && nums[i] <= nums[i - k]) {
                isGood = false;
            }
            
            if (i + k < nums.size() && nums[i] <= nums[i + k]) {
                isGood = false;
            }
            
            if (isGood) {
                sum += nums[i];
            }
        }
        return sum;
    }
};