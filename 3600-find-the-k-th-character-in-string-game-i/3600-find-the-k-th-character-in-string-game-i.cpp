class Solution {
public:
    
    char kthCharacter(int k) {
        string word = "a";
        while(word.length() < k){
            int currSize = word.length();
            for(int i=0;i<currSize;i++){
                char nextChar = 'a' + ((word[i]-'a'+1)%26);
                word += nextChar;
            }
        }
        return word[k-1];
    }
};