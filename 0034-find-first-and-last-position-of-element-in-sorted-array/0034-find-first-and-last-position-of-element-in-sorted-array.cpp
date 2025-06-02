class Solution {
public:
    int lb(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0,h = n-1;
        int ans = n;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid] >= target){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int ub(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0,h = n-1;
        int ans = n;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid] > target){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lb(nums, target);
        int second = ub(nums,target);
        
        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }
        return {first,second-1};
    }
};