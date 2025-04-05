class Solution {
public:
    void solve(vector<int>& nums,vector<int>& curr,int idx,int& xorSum){
        if(idx == nums.size()){
            int xorVal= 0;
            for(int num: curr){
                xorVal ^= num;
            }
            xorSum += xorVal;
            return;
        }
        curr.push_back(nums[idx]);
        solve(nums,curr,idx+1,xorSum);
        curr.pop_back();
        solve(nums,curr,idx+1,xorSum);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int xorSum = 0;
        vector<int>curr;
        solve(nums,curr,0,xorSum);
        return xorSum;  
    }
};