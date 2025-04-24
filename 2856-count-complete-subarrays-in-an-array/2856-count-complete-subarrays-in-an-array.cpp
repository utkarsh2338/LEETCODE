class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int c = unordered_set<int>(nums.begin(),nums.end()).size();
        int i=0,j=0;
        unordered_map<int,int>mpp;
        int ans = 0;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size() == c){
                ans += n-j;
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};