class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int minKPos = -1,maxKPos = -1,culpritIdx  = -1;
        for(int i=0;i<n;i++){
            if(nums[i] < minK || nums[i] > maxK) culpritIdx = i;
            if(nums[i] == minK) minKPos = i;
            if(nums[i] == maxK) maxKPos = i;

            long long small = min(minKPos,maxKPos);
            long long temp = small - culpritIdx;
            ans += temp<=0 ? 0 : temp;
        }
        return ans;
    }
};