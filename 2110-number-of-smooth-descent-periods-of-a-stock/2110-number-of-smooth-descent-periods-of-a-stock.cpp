class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 1;
        long long d=1,sum=1;
        for(int i=1;i<n;i++){
            d = (prices[i]+1==prices[i-1])*d+1;
            sum += d;
        }
        return sum;
    }
};