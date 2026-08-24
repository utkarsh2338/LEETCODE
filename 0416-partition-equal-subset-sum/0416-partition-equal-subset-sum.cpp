class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // sum -> equal
        int totalSum = 0,n = nums.size();
        for(auto& num : nums){
            totalSum += num;
        }
        if(totalSum % 2 !=0) return false;
        int targetSum = totalSum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(targetSum+1,false));
        for(int i=0;i<n+1;i++){
            dp[i][0] = true;
        }
        for(int i=1;i<n+1;i++){
            for(int j =1;j<targetSum+1;j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][targetSum];
    }
}; 