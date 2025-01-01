class Solution {
public:
    bool allZeroes(vector<int>&counter){
        for(int &it:counter){
            if(it != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        vector<int>counter(26,0);
        for(int i=0;i<p.length();i++){
            char ch = p[i];
            counter[ch-'a']++;
        }
        int l = 0;
        int r = 0;
        while(r<s.length()){
            counter[s[r]-'a']--;
            if(r-l+1 == p.length()){// window baraabar ho gya ya nhi vo check kr rhe
                if(allZeroes(counter)){
                    ans.push_back(l);
                }
            counter[s[l]-'a']++;
            l++;
            }
            r++;
        }
        return ans;
    }
};