class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i=0,j=0;
        unordered_map<int,int>mpp;
        int sum = 0,maxLen =0;
        while(j<n){
            mpp[fruits[j]]++;
            sum += fruits[j];
            while(mpp.size() > 2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0){
                    mpp.erase(fruits[i]);
                }
                i++;
            }
            maxLen = max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};