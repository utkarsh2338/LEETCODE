class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int & it: nums){
            mpp[it]++;
        }
        int maxFreq = 0;
        int cnt = 0;
        for(auto &it: mpp){
            maxFreq = max(maxFreq,it.second);
        }
        for(auto& it: mpp){
            if(it.second == maxFreq) cnt += it.second;
        }
        return cnt;
    }
};