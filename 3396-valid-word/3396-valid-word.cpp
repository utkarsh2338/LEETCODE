class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if(n<3) return false;

        int vowels = 0,consonents = 0;
        string vowel = "aeiouAEIOU";
        for(char ch: word){
            if(isalpha(ch)){
                if(vowel.find(ch) != string::npos){
                    vowels++;
                }
                else{
                    consonents++;
                }
            }
            else if(!isdigit(ch)){
                return false;
            }
        }
        return vowels>=1 && consonents>=1;
    }
};