class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        int sum = 0;// to store the sum of 0 and 1 every time i will encounter 1 will increse the sum to 1 and decrese to 1 if 0, and if sum is 0 so maxLength will be equal to i+1;
        unordered_map<int,int>mpp;// to store the sum and its index 
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                sum--;
            }
            else{
                sum++;
            }
            if(sum == 0){
                maxLength = i+1;
            }
            if(mpp.find(sum) != mpp.end()){
                // update the maxLength
                maxLength = max(maxLength,i-mpp[sum]);
            }
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return maxLength;
    }
};