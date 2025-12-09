#define MOD 1000000007
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>l,r;
        for(int it: nums){
            r[it]++;
        }
        for(int j =0;j<n;j++){
            int mid = nums[j];
            r[mid]--;
            int left = l[2*mid];
            int right = r[2*mid];
            ans = (ans+ 1LL * left*right)%MOD;
            l[mid]++;
        }
        return ans;
    }
    
};