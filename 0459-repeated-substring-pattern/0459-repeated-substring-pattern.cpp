// kmp algorithm
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if(n<=1) return false;
        vector<int>lps(n,0);// lowest common prefix which is also suffix
        for(int i=1,len=0;i<n;){
            if(s[i] == s[len]){
                ++len;
                lps[i++] = len;
            }
            else if(len>0) len = lps[len-1];
            else lps[i++] = 0;
        }
        int l = lps[n-1];
        return l>0 && (n%(n-l) == 0);
    }
};