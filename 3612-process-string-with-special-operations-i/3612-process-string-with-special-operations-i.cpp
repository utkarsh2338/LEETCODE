class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string res = "";
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch>='a' && ch<='z'){
                res+= ch;
            }
            
            else if(s[i] == '*'){
                if(!res.empty())res.pop_back();
            }
           else if(s[i] == '#'){
                res += res;
            }
            else if(s[i] == '%'){
                reverse(res.begin(),res.end());
            }
            
        }
        return res;
    }
};