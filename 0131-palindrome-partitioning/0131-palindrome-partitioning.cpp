class Solution {
public:
    int n;
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void backtrack(string s, int idx, vector<vector<string>>& ans,
                   vector<string>& curr) {
        if (idx == n) {
            ans.push_back(curr);
            return;
        }
        // ye jo loop chalta hai vo hamesha partition ke liye chalta hai ye baat
        // ka dhyan rakhkr hamesha code ko likhna
        //time complexity 0(2^n*n)
        for (int i = idx; i < n; i++) {
            if (isPalindrome(s, idx,i)) { // agr ye hai tabhi mai explore karunga
                curr.push_back(s.substr(idx,i-idx+1));// substr me index aur length paas karna hota hai
                backtrack(s, i + 1, ans, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(s, 0, ans, curr);
        return ans;
    }
};