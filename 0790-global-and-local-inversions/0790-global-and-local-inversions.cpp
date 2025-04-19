class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int countL = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1] == nums[i] + 1) {
                swap(nums[i],nums[i-1]);
            }
            else if(nums[i-1] != i-1) return false;
        }
        return true;
    }
};