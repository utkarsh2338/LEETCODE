class Solution {
public:
    bool isSubset(vector<int>&freq2,vector<int>&temp){
        for(int i=0;i<26;i++){
            if(temp[i] < freq2[i]){
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        // making a vector of 26 size to store the frequency of characters of words2
        vector<int>freq2(26);
        for(string& word: words2){
            vector<int> temp(26,0);// all the characters have 0 frequency
            for(char& ch:word){ 
                temp[ch-'a']++;

                freq2[ch-'a'] = max(freq2[ch-'a'],temp[ch-'a']);
            }
        }

        for(string& word: words1){
            vector<int>temp(26,0);
            for(char& ch: word){
                temp[ch-'a']++;
            }
            if(isSubset(freq2,temp)==true){
                ans.push_back(word);
            }
        }
        return ans;
    }
};