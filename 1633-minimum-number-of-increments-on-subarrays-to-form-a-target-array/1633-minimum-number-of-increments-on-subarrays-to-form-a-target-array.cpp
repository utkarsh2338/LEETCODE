class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ops = 0;
        int n = target.size();
        vector<int>initial(n,0);
        int curr = 0;
        int prev = 0;
        for(int i=0;i<n;i++){
            curr = target[i] - initial[i];
            if((curr < 0 && prev > 0) || (curr > 0 && prev < 0)){
                ops += abs(curr);
            }
            else if(curr > prev){
                ops += abs(curr - prev);
            }
            prev = curr;
        }
        return ops;
    }
};