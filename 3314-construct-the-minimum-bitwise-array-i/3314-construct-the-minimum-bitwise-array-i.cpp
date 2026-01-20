class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (auto& i : nums) {
            if (i == 2) {
                ans.push_back(-1);
                continue;
            }
            for (int j = 1; j < i; j++) {
                if ((j | (j + 1)) == i) {
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};