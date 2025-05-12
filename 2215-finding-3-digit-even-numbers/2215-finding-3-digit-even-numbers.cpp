class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int& it:digits){
            mpp[it]++;
        }

        for(int i=100;i<=999;i+=2){
            int a = i / 100;
            int b = (i/10) % 10;
            int c = i % 10;

            unordered_map<int,int>temp = mpp;
            if (--temp[a] >= 0 && --temp[b] >= 0 && --temp[c] >= 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};