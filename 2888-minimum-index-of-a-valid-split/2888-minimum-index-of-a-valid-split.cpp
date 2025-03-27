class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dominant = -1;
        unordered_map<int, int> mpp;
        for (int& it : nums) {
            mpp[it]++;
        }
        for(auto&[key,val]:mpp){
            if(val > (n/2)){
                dominant = key;
            }
        }
        
        if(dominant == -1) return -1;
        int prefixCount = 0,suffixCount = mpp[dominant];
        for(int i=0;i<n-1;i++){
            if(nums[i] == dominant){
                prefixCount++;
                suffixCount--;
            }
            if((prefixCount*2 > i+1) && (suffixCount *2 > n-i-1)) return i;
        }
        return -1;
    }
};