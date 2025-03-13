class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // first number jo ki >=1 hai
        int n = nums.size();
        int idx1 = lower_bound(begin(nums),end(nums),1) - begin(nums);
        int posCount = n - idx1; 
        // aur ab ham nikalenge pahla index jahapar value >= 0 hai 
        int idx0 = lower_bound(begin(nums),end(nums),0) - begin(nums);
        return max(posCount,idx0);
    }
};