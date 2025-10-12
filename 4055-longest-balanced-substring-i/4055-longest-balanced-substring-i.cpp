class Solution {
public:
    bool isBalanced(vector<int>&freq,int t){
        for(int it: freq){
            if(it != 0 && it != t) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(isBalanced(freq,freq[s[j]-'a'])){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};