class Solution {
public:
    using ll = long long;
    int distinctSubseqII(string s) {
        const ll MOD = 1000000007;
        ll dp = 1;
        vector<ll> last(26,0);
        for(char ch: s){
            int idx = ch-'a';
            ll oldDp = dp;
            dp = (2*dp-last[idx]+MOD)%MOD;
            last[idx] = oldDp;
        }  
        return (dp-1+MOD)%MOD;
    }
};