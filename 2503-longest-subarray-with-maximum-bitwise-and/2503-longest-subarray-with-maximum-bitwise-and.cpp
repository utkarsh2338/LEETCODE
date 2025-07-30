class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int maxLen =0,len=0;
        for(int &x: nums){
            if(x == maxEle){
                len++;
            }
            else{
                maxLen = max(maxLen,len);
                len = 0;
            }
        }
        return max(maxLen,len);
    }
};