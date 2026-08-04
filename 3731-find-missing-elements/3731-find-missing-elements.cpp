class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        unordered_set<int>s(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            if(!s.count(i)) ans.push_back(i);
        }
        return ans;
    }
};