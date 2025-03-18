class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i =0,j=0;
        int n = s.length();
        int ans = 0;
        vector<int>charCount(256,0);// count store karne ke liye

        while(j<n){
            charCount[s[j]]++;// state ko update karne ki condition
            // ab yaha par valid aur invalid wala
            while(charCount[s[j]] > 1){
                charCount[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};