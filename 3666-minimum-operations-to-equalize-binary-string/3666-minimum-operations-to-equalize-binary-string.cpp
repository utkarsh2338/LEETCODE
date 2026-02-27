class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int cnt0 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0') cnt0++;
        }
        int cnt1= n-cnt0;
        if(!cnt0){
            return 0;
        }
        if(n == k){
            return ((cnt0==n)<<1)-1;
        }
        int base = n-k;
        int odd = max(
            (cnt0+k-1)/k,
            (n-cnt0+base-1)/base
        );
        odd += ~odd & 1;
        int even = max(
            (cnt0 + k-1)/k,
            (cnt0+base-1)/base
        );

        even += even&1;
        int res = INT_MAX;
        if((k&1) == (cnt0&1)) res = min(res,odd);
        if(~cnt0 & 1) res = min(res,even);
        return res == INT_MAX ? -1:res;
    }
};