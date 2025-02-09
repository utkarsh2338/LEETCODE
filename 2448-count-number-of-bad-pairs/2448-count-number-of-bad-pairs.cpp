class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // ab ham lagayenge approach jo ki 0(1) space me ho jye
        long long count = 0;
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int diff = i  - nums[i];
            int goodPairsCount = mpp[diff];
            count += i - goodPairsCount;
            mpp[diff] = goodPairsCount + 1;
        }
        // ye ban gaya map mera index aur values ka ab iterate karte hain ispe
        return count;
    }
};