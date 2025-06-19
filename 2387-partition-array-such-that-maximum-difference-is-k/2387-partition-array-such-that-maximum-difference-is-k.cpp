class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i =0,j= n-1;
        int cnt = 0;
        for(int i =0;i<n;   ){
            int start = nums[i];
            cnt++;
            i++;
            while(i<n && nums[i] - start <= k){
                i++;
            }
        }
        return cnt;
    }
};