class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> st;
        int i = 0;
        for(i = nums.size() - 1; i >= 0; i--) {
            if (st.count(nums[i])) break;
            st.insert(nums[i]);
        }
        return (i + 3) / 3;
    }
};