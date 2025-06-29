#define MOD 1000000007
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>pow2(n,1);
        for(int i=1;i<n;i++){
            pow2[i] = (pow2[i-1]*2)%MOD;
        }
        int l = 0, r= n-1;
        long long res = 0;
        while(l<=r){
            if(nums[l] + nums[r] <= target){
                res += (pow2[r-l]) % MOD;
                l++;
            }
            else{
                r--;
            }
        }
        return res%MOD;
    }
};