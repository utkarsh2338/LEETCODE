class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>LtoR(n,1),RtoL(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                LtoR[i] = max(LtoR[i],LtoR[i-1]+1);
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                RtoL[i] = max(RtoL[i],RtoL[i+1]+1);
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res += max(LtoR[i],RtoL[i]);
        }
        return res;
    }
};