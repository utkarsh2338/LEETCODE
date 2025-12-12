class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string rep = "";
        int cnt = 0;
        while ((int)rep.length() < (int)b.length()) {
            rep += a;
            ++cnt;
        }
        if (rep.find(b) != string::npos) return cnt;
        rep += a;
        ++cnt;
        if (rep.find(b) != string::npos) return cnt;
        return -1;
    }
};