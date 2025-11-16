class Solution {
public:
    int numSub(string s) {
        int n=s.length();
        int cnt=0,total =0,mod=1e9+7;
        for(int i=0;i<n;i++){
            if(s[i] == '1') cnt++;
            else cnt = 0;
            total = (total + cnt)%mod;
        }
        return total;      
    }
};