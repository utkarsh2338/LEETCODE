class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st(brokenLetters.begin(),brokenLetters.end());
        int cnt = 0;
        string word;
        stringstream ss(text);// used to split words by space
        while(ss>>word){
            bool ok = true;
            for(char ch: word){
                if(st.count(ch)){
                    ok = false;
                    break;

                }
            }
            if(ok) cnt++;
        }
        return cnt;
    }
};