class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0,r=0;
        int countOfZeroes = 0;
        int maxLength = 0;
        int n = nums.size();
        while(r<n){
            if(nums[r] == 0){
                countOfZeroes++;
                }
            if(countOfZeroes > k){
                if(nums[l] == 0){
                countOfZeroes--;
            }
            l++;
            }
            
            if(countOfZeroes <= k){
                int length = r-l+1;
                maxLength = max(maxLength,length);
            }
            r++;
        }
        return maxLength;
    }
};