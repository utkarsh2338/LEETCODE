class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string str = to_string(n);
        map<char,int>mpp;
        int mini = INT_MAX;
        for(int i=0;i<str.size();i++){
            mpp[str[i]]++;
        }
        char ans = '9';
        for(auto p: mpp){
            if(p.second < mini || (p.second == mini && p.first < ans)){
                mini = p.second;
                ans = p.first;
            }
        }
        return ans-'0';
    }
};