class Solution {
private:
    void solve(vector<int> nums,vector<vector<int>>& ans,int index){
        //base case
        if(index >=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i= index;i<nums.size();i++){
            swap(nums[index],nums[i]);//ek case maine sambhal liya baki ab mera recursion sambhaal lega
            solve(nums,ans,index+1);
            //backtracking
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums,ans,index);
        return ans;
    }
};