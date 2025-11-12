class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt1 =0;
        int n = nums.size();
        for(int&it: nums){
            if(it == 1) cnt1++;
        }
        if(cnt1) return n-cnt1;
        int i=0,j=0;
        int minLength = INT_MAX;
        for(int i=0;i<n;i++){
            int g = nums[i];
            for(int j=i+1;j<n;j++){
                g = gcd(g,nums[j]);
                if(g == 1){
                    minLength = min(minLength,j-i+n-1);
                    break;
                }
            }
        }
        if(minLength == INT_MAX) return -1;
        else return minLength;
    }
};