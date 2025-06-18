class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        int n = strs.size();
        string pref = strs[0];
        int prefLen = pref.size();
        for(int i=1;i<n;i++){
            string st = strs[i];
            while(prefLen > st.length() || pref != st.substr(0,prefLen)){
                prefLen --;
                if(prefLen == 0){
                    return "";
                }
                pref = pref.substr(0,prefLen);
            }
        }
        return pref;
    }
};