class Solution {
public:
    string robotWithString(string s) {
        string t = "";
        string p = "";
        int n = s.length();
        vector<char>minCharToRight(n);
        minCharToRight[n-1] = s[n-1];
        for(int i=n-2;i>=0;i--){
                minCharToRight[i] = min(s[i],minCharToRight[i+1]);
        }
        // yaha tak ban gaya mera mincharToRight wala vector
        int i =0;
        while(i<n){
            t.push_back(s[i]);
            char minChar = (i+1 < n) ? minCharToRight[i+1] : s[i];
            while(!t.empty() && t.back() <= minChar){
                p += t.back();
                t.pop_back();
            }
            i++;
        }

        // fill the remaining char
        while(!t.empty()){
            p+= t.back();
            t.pop_back();
        }
        return p;
    }
};