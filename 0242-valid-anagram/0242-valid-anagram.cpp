class Solution {
public:
    bool isAnagram(string s, string t) {
        bool found = true;
        if(s.length() != t.length()) return false;
        unordered_map<char, int> mpp;

        for (char ch : s) {
            mpp[ch] = mpp[ch] + 1;
        }
        for(char ch:t){
            if(mpp.find(ch) == mpp.end() || mpp[ch] == 0){
                return false;
            }
            mpp[ch] = mpp[ch] -1;
        }
        return true;
    }
};