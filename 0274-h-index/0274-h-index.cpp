class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>freq(n+1,0);
        for(int x:citations){
            freq[min(x,n)]++;
        }
        int cummPapers = 0;
        for(int i=n;i>=0;i--){
            cummPapers += freq[i];
            if(cummPapers >= i){
                return i;
            }
        }
        return -1;
    }
};