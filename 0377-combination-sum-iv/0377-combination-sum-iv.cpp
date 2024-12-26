class Solution {
public:
    int n;
    int t[201][1001];
    int solve(int idx,int target,vector<int>&nums){
        if(target == 0){
            return 1;
        }
        if(idx>=n || target <0){
            return 0;
        }
        if(t[idx][target] != -1){
            return t[idx][target];
        }
        int take_idx = solve(0,target-nums[idx],nums);
        int not_take_idx = solve(idx+1,target,nums);
        return t[idx][target] = take_idx + not_take_idx;

    } 
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t,-1,sizeof(t));;
        return solve(0,target,nums);
    }
};