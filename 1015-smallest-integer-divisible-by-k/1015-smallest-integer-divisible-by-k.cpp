class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num =0;
        for(int length = 0;length<=k;length++){
            num = (num*10+1)%k;
            if(num % k == 0){
                return length+1;
            }
        }
        return -1;
    }
};