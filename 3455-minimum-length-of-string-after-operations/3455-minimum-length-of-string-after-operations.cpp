class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int>hash(26,0);
        // we will count the frequency of each characters and then according to the frequency we will do the operation
        for(int i=0;i<n;i++){
            hash[s[i] - 'a']++;
            if(hash[s[i] - 'a'] == 3){
                hash[s[i] -'a'] -= 2;// deleted two characters
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(hash[i] == 0) continue;
            ans += hash[i];
        }
        // for example: if frequency of a is 3 then only we can remove one character from front and one from end

    return ans;
    }
};