#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
            ll n = nums.size();
            vector<int> ps(n + 1, 0);
            ll i =0,j=0,sum=0,cnt=0;
            for(ll j=0;j<n;j++){
                sum += nums[j];
                while(sum*(j-i+1)>=k){
                    sum-=nums[i];
                    i++;
                }
                cnt += j-i+1;
            }
            return cnt;  
        }
};