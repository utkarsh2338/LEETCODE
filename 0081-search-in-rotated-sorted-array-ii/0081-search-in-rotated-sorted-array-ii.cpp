class Solution {
public:
    // function for finding pivot
    int f(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<r){
            while(l<r && nums[l] == nums[l+1]){
                l++;
            }
            while(l<r && nums[r] == nums[r-1]){
                r--;
            }
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return r;
    }
    bool binarySearch(vector<int>& nums,int l,int r, int target){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int pivot = f(nums,target);
        int n = nums.size();
        if(binarySearch(nums,0,pivot-1,target)) return true;
        return binarySearch(nums,pivot,n-1,target);
    }
};