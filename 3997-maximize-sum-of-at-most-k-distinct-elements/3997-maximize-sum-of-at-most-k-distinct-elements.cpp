class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int>ans;
        unordered_set<int>st;
        
        for(auto &it: nums){
            if(!st.count(it)){
                ans.push_back(it);
                st.insert(it);
                if(ans.size() == k) break;
            }
                
        }   
        return ans;
    }
};