class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int& it: nums){
            mpp[it]++;
        }
        for(auto& pair: mpp){
            if(pair.second % 2 != 0){
                return false;
            }
        }
        return true;
    }
};