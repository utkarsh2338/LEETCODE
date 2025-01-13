class Solution {
public:
    int minimumLength(string s) {
        // we will go with the first approach that is by counting the frequency of each characters
        // the approach is simple count the frequency of each character and then if the frequency of any particular character goes 3 then remove the count of that frequency by 2 that is from the front and from the end;
        int n = s.length();
        vector<int>hash(26,0);// we are not taking the map because there is only lower case alphabets in the string if it would have been both lowercase as well as upper case then we would have taken the map
        for(int i=0;i<n;i++){
            hash[s[i] -'a']++;
            if(hash[s[i] - 'a'] == 3){
                hash[s[i] - 'a'] -= 2; 
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            ans += hash[i];
        }
        return ans;
    }
};