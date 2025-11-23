class Solution {
public:
    int minimumFlips(int n) {
        int L = 32- __builtin_clz(n);
        int flips = 0;
        for(int i=0;i<L/2;i++){
            int lBit = (n>>i)&1;
            int rBit = (n>>(L-i-1))&1;

            if(lBit != rBit) flips+=2;
        } 
        return flips;
    }
};