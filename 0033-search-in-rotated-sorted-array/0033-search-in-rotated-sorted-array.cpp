class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] ==  target) return mid;
            if(nums[s]<=nums[mid]){
                //left half is sorted we can apply binary search here
                if(nums[s]<=target && target<=nums[mid]){
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
            else{
                //right half is sorted b s apply here
                if(nums[mid]<=target && target<=nums[e]){
                    s = mid + 1;
                }
                else{
                    e = mid - 1;
                }
            }
        }
return -1;

    }
};