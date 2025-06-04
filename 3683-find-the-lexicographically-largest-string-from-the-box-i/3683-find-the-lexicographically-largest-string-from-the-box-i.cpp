class Solution {
public:
    string answerString(string word, int numFriends) {
        string ans;
        if(numFriends==1) return word;
        int n = word.length();
        int longestPossible = n-(numFriends-1);
        for(int i=0;i<n;i++){
            int canTakeLength = min(longestPossible,n-i);
            ans = max(ans,word.substr(i,canTakeLength));  
        }
        return ans;
    }
};