class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1.length() != s2.length()){
            return false;
        }
        int cnt[256] = {0};
        for(int i=0;i<s1.length();i++){
            int offset = (i&1) << 7;
            cnt[offset + s1[i]]++;
            cnt[offset + s2[i]]--;
        }
        for(int i=0;i<256;i++){
            if(cnt[i] != 0){
                return false;
            }
        }
        return true;
    }
};