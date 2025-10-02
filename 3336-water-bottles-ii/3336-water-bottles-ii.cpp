class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int cnt  = 0;
        while(numBottles > 0){
            emptyBottles += numBottles;
            cnt += numBottles;
            numBottles = 0;
            if(emptyBottles >= numExchange){
                numBottles += 1;
                emptyBottles -= numExchange;
                numExchange += 1;
            }
        } 
        return cnt;
    }
};