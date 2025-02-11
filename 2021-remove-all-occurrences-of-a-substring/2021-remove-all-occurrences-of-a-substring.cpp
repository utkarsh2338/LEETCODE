class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int target = part.size();
        int endChar = part.back();

        for(char ch: s){
            ans.push_back(ch);
            if(ch == endChar && ans.size() >= target){
                if(ans.substr(ans.size() - target) == part){
                    ans.erase(ans.size() - target);
                }
            }
        }
        return ans;
    }
};