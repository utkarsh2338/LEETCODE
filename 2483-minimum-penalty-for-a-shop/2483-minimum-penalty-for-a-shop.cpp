class Solution {
public:
    int bestClosingTime(string customers) {
        // Y -> customer came at ith hour
        // N -> No customer came at ith hour
        int minPenalty = 0;
        int bestTime = 0;
        int prefix = 0,n=customers.length();
        for(int i=0;i<n;i++){
            if(customers[i] == 'Y'){
                prefix += -1;
            }
            else prefix += 1;

            if(prefix < minPenalty){
                bestTime = i+1;
                minPenalty = prefix;
            }
        }
        return bestTime;
    }
};