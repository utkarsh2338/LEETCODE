class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int shiftTimes = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            shiftTimes = (shiftTimes + shifts[i]) % 26;// total no. of alphabets are 26 and the string is treatting with the cyclic alphabets that'sm why a modulo is added
            s[i] = (s[i] - 'a' + shiftTimes) % 26 + 'a';
        }
        return s;
    }
};