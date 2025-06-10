class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();
        vector<int>freq(26,0);
        for(int ch=0;ch<n;ch++){
            freq[s[ch]-'a']++;
        }
        int a1 = 0,a2 = s.size();
        for(int i=0;i<freq.size();i++){
            if(freq[i] % 2 != 0){
                a1 = max(a1,freq[i]);
            }
            if(freq[i] % 2 == 0 && freq[i] > 0){
                a2 = min(a2,freq[i]);
            }
        
        }
        return a1-a2;
    }
};