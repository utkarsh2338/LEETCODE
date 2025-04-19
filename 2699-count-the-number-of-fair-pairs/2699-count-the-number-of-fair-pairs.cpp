// class Solution {
// public:
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         int n = nums.size();
//         long long count = 0; 
//         for(long long i =0;i<n;i++){
//             for(long long j = i+1;j<n;j++){
//                 if(nums[i]+nums[j]>=lower && nums[i]+nums[j]<=upper){
//                     count ++;
//                 }
//             }
//         }
//         return count;
//     }
// };

// // The above solution is giving me TLE

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Step 1 -> sort the nums array
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long count = 0;
        // using two pointers technique
        for(int i=0;i<n;i++){
            int left = i+1;
            int minSum = lower-nums[i];
            int maxSum = upper-nums[i];
            // Use lower_bound and upper_bound to find the range of valid pairs
            auto low = lower_bound(nums.begin() + left, nums.end(), minSum);
            auto high = upper_bound(nums.begin() + left, nums.end(), maxSum);
            count += distance(low, high);
        }
        return count;
    }
};
