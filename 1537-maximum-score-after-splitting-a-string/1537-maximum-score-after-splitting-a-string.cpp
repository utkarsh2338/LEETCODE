class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        // calculating the number of ones in starting only
        int noOfOnes = count(s.begin(),s.end(),'1');
        int noOfZeroes = 0;// count while iterating
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(s[i] == '0') noOfZeroes++;
            if(s[i] == '1') noOfOnes--;
            ans = max(ans,noOfOnes+noOfZeroes);
        }
        return ans;
    }
};