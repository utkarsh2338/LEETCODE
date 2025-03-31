class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int>adjSum(n-1,0);
        for(int i=0;i<n-1;i++){
            adjSum[i] += weights[i]+weights[i+1];
        }
        sort(adjSum.begin(),adjSum.end());
        long long res = 0;
        for(int i=0;i<k-1;i++){
            res += adjSum[n-2-i] - adjSum[i];
        }
        return res;
    }
};