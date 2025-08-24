class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto &it: nums){
            mpp[it]++;
        }
        for(auto& it: mpp){
            if(it.second > nums.size()/k) return false;
        }
        return nums.size()%k==0;
    }
};