class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;
        for(int i=0;i<word.size();i++){
            if(word[i] == word[i+1]) {
                count++;
            }
        }
        if(count>1) return count;
        else return 1;
    }
};


