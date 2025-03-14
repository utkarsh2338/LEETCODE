class Solution {
    private:
        bool canAllocate(int mid,long long k,vector<int>& candies){
            int n = candies.size();
            for(int i=0;i<n;i++){
                k -= candies[i]/mid;

                if(k <= 0){
                    return true;
                }
            }
            return k <= 0;
        }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxCand = 0;
        long long totalCand = 0;
        for(int i=0;i<n;i++){
            totalCand += candies[i];
            maxCand = max(maxCand,candies[i]);
        }
        if(totalCand < k){
            return 0;
        }
        int res = 0;
        int l = 1;
        int r = maxCand;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(canAllocate(mid,k,candies)){
                res = mid;
                l = mid+1;
            }
            else {
               r = mid-1;
            }
        }
        return res;
    }
};