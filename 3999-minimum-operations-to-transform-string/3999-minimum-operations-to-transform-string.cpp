class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for(char ch: s){
            int distance = (26-(ch-'a'))%26;
            ans = max(ans,distance);
        }
        return ans;
    }
};