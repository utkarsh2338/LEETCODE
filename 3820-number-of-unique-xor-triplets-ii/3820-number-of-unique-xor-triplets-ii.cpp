class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>st,s;
        int n = nums.size();
        if(n<3) return n;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                st.insert(nums[i]^nums[j]);
            }
        }
        for(auto& num:st){
            for(auto& x: nums){
                s.insert(num^x);
            }
        }
        return s.size();
    }
};