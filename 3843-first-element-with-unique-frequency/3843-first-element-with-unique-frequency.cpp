class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mpp1,mpp2;
        for(auto it:nums){
            mpp1[it]++;
        }
        // mpp1 -> 20->1, 10->1, 30->2
        for(auto it: mpp1){
            mpp2[it.second]++;
        }
        // mpp2 -> 1->2 , 2->1
        for(int i=0;i<nums.size();i++){
            if(mpp2[mpp1[nums[i]]] == 1){
                return nums[i];
            }
        }
        return -1;
    }
};