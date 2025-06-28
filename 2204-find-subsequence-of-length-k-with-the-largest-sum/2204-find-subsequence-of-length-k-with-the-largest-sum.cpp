class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>numsIndex;
        for(int i=0;i<nums.size();i++){
            numsIndex.push_back({nums[i],i});
        }
        sort(numsIndex.begin(), numsIndex.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });
             vector<pair<int, int>> topK(numsIndex.begin(), numsIndex.begin() + k);
        sort(topK.begin(), topK.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        // Extract values
        vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};