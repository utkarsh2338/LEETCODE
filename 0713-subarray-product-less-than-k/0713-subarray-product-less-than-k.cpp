class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int prod = 1;
        int ans = 0;
        if(k == 0) return 0;
        while(j<n){
            prod *= nums[j];
            while(i <= j && prod >= k){
                prod /= nums[i++];
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
};