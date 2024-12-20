// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size()-1;
//         int s = 0;
//         int e = nums.size()-1;
//         vector<int>ans;
//         //  binary search to find first position of an element 
//         while(s<=e){
//             int mid = s+(e-s)/2;
//             if(nums[mid] == target){
//                 if(mid>0 && nums[mid-1] == nums[mid]){
//                     e = mid-1;
//                 }
//                 else{
//                     ans.push_back(mid);
//                 }
//             }
//             else if(nums[mid] > target){
//                 s = mid+1;
//             }
//             else {
//                 e = mid-1;
//             }
//         }
//         // binary search to find the second position of the element
//         while(s<=e){
//             int mid = s+(e-s)/2;
//             if(nums[mid]== target){
//                 if(mid<n-1 && nums[mid]== nums[mid+1]){
//                     s = mid+1;
//                 }
//                 else{
//                     ans.push_back(mid);
//                 }
//             }else if(nums[mid] > target){
//                 s = mid+1;
//             }
//             else {
//                 e = mid-1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1); // Initialize result as {-1, -1}

        int s = 0, e = nums.size() - 1;

        // Binary search for the first position
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans[0] = mid; // Found the target
                e = mid - 1; // Move left to find the first occurrence
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        // Binary search for the last position
        s = 0;
        e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans[1] = mid; // Found the target
                s = mid + 1; // Move right to find the last occurrence
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
