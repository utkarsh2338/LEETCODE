// now the tabulation appraoch bottom - up approach where we will define the states first and then use the for loop
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1);
        // dp[i] ka matlab hoga max stolen money till i
        // isme problem aa rahi thi initial states define karne me toh ham kya karenge upar wali line ka use karenge aur apna array fill karege 
        dp[0] = 0;// iska matlab max stolen money till zero house ab zero house hai toh 0 money
        dp[1] = nums[0];// ek house matlab agr ek hi ghar hai toh obv vo array ka pahla hi element hoga
        for(int i=2;i<=n;i++){
            int steal = nums[i-1] + dp[i-2];
            int skip = dp[i-1];
            dp[i] =  max(steal,skip);
        }
        return dp[n];
    }
};