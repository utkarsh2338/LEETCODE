class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currSum = nums[0];
        int sum = nums[0];
        int n = nums.size(); 
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                currSum += nums[i];
            }
            else{
                currSum = nums[i];
            }
            sum = max(currSum,sum);
        }
        return sum;
    }
};