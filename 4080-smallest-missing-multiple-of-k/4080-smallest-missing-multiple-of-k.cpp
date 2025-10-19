class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st(nums.begin(),nums.end());
        int curr = k;
        while(st.find(curr) != st.end()){
            curr += k;
        }
        return curr;
    }
};