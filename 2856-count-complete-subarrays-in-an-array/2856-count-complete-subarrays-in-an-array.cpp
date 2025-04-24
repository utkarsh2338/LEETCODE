// Naive solution generating all the subarrays
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int distinct_elements = unordered_set<int>(nums.begin(),nums.end()).size();
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                if(st.size() == distinct_elements) ans++;
            }
        }
        return ans;
    }
};