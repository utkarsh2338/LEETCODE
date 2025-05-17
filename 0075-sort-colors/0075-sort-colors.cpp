class Solution {
public:
    void sortColors(vector<int>& nums) {  // Keep return type void
        int n = nums.size();
        for(int i = 0; i < n-1; i++) {
            int minIdx = i;
            for(int j = i+1; j < n; j++) {
                if(nums[j] < nums[minIdx])
                    minIdx = j;  // Correct the logic
            }
            swap(nums[i], nums[minIdx]);  // Modify nums in place
        }
    }
};
