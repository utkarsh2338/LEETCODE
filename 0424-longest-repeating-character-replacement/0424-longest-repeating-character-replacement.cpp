class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        int l = 0, r = 0;
        int n = s.length();
        int maxFreq = 0;
        vector<int> hash(26, 0);
        while (r < n) {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            int changes = (r - l + 1) - maxFreq;
            if(changes > k) {

                hash[s[l] - 'A']--;
                maxFreq = 0;
                l++;
            } if (changes <= k) {
                maxLength = max(maxLength, r - l + 1);
            }
            r++;
        }
        return maxLength;
    }
};