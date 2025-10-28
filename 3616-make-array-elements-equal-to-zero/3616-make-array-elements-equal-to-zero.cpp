class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0, left = 0,right = 0;
        for(int x: nums) right += x;
        for(int i=0;i<n;i++){
            left += nums[i];
            right -= nums[i];
            if(nums[i] != 0) continue;
            if(left == right) count += 2;
            if(abs(left-right) == 1) count++;
        }
        return count;
    }
};