// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<int>ans;
//         sort(nums.begin(),nums.end());
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             if (i > 0 && nums[i] == nums[i-1]) {
//                 continue;
//             }
//             int j=i+1;
//             int k= n-1;
//             while(j<k){
//                 int total = nums[i]+nums[j]+nums[k];
//                 if(total>0){
//                     k--;
//                 }
//                 else if(total<0){
//                     j++;
//                 }
//                 else{
//                 ans.push_back({nums[i], nums[j], nums[k]});
//                     j++;
//                     while(nums[j]==nums[j-1] && j<k){
//                         j++;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };
/*
Approach: 

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; // Change to 2D vector
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip duplicate elements for the first number
            }
            
            int j = i + 1; // Initialize second pointer
            int k = n - 1; // Initialize third pointer
            
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                
                if (total > 0) {
                    k--; // Decrease the sum
                } else if (total < 0) {
                    j++; // Increase the sum
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]}); // Found a triplet
                    j++;
                    k--; // Move both pointers

                    // Skip duplicates for the second number
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    // Skip duplicates for the third number
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return ans; // Return the result
    }
};
