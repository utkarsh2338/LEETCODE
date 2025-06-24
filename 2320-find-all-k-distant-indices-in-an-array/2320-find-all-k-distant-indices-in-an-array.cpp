class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int>st;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i] == key){
                for(int j=0;j<n;j++){
                    if(abs(j-i) <= k){
                        st.insert(j);
                    }
                }
            }
        }
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};