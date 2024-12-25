class Solution {
public:
    int n;
    void backtrack(
        vector<int>& nums, int idx, vector<int>& curr,
        vector<vector<int>>&
            ans) { // sabse pahle ham ye check karenge ki kya hamara current
                   // vector jo ham ban arahe hai uska length 2 ya do se bada
                   // hai ya nahi tabhi ham usko include karenge
        if (curr.size() >= 2) {
            ans.push_back(curr);
        }
        // ek unordered set ham banayenge jo ki use hoga duplicacy ko bachane ke
        // liye'
        unordered_set<int> st;
        for (int i = idx; i < n; i++) {
            // now check the current vector is empty() or the element at the end
            // should not equal to the current element and the element should
            // not be included in the set agr ye sari cheeze satisfy ho ja rahi
            // tabhi mai current ke andar uss elemt ko dalunga
            if ((curr.empty() || nums[i] >= curr.back()) &&
                (st.find(nums[i]) == st.end())) {
                // apne current wale vector ke andar daal do vo element
                curr.push_back(nums[i]); // take the element
                // backtrack call again
                backtrack(nums, i + 1, curr, ans);
                curr.pop_back(); // backtrack the result or not take the result

                st.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        // ek 2d array jo ki mera result store karega
        vector<vector<int>> ans;
        // ek vector jo ki mera current subsequence ko store karega
        vector<int> curr;
        backtrack(nums, 0, curr, ans);
        return ans;
    }
};