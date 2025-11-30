class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(k==0) return nums.size();
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int x = nums[n-k];
        int ans =0;
        for(int num: nums){
            if(num<x){
                ans++;
            }
        }
        return ans;
    }
};