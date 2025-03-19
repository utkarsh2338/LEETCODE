class Solution {
public:
    /*
    for each index i, we check whether nums[i - 2] is still 0. If it is, then we
    must flip the triplet ending at i (nums[i - 2], nums[i - 1], nums[i]).
    */
    int minOperations(vector<int>& nums) { 
        int count = 0;
        int n = nums.size(); 
        for(int i=2;i<n;i++){
            if(nums[i-2] == 0){
                count++;
                // flip using xor
                nums[i-2] ^= 1;
                nums[i-1] ^= 1;
                nums[i] ^= 1;
            }
        }
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum == nums.size()) return count;// that means all the elements are 1
        return -1;
        }
};