class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string>ans;
        string st = "";
        for(int i =0;i<n;i++){
            st += s[i];
            if(st.size() == k){
                ans.push_back(st);
                st = "";
            }
        }
        if(!st.empty()){
                while(st.length()<k){
                    st+= fill;
                }
                ans.push_back(st);
            }
        return ans;
    }
};