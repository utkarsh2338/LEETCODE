class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string t = "";
        for(char c : s) {
            if(c != '-') t += toupper(c);
        }

        int n = t.size();
        if(n == 0) return "";

        int firstGroup = n % k;
        string ans = "";
        int i = 0;

        // Add first group (if exists)
        if(firstGroup > 0) {
            ans += t.substr(0, firstGroup);
            i = firstGroup;
            if(i < n) ans += "-";
        }

        // Add remaining groups of size k
        while(i < n) {
            ans += t.substr(i, k);
            i += k;
            if(i < n) ans += "-";
        }

        return ans;
    }
};
