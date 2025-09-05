#define ll long long
class Solution {
public:

    int makeTheIntegerZero(int num1, int num2) {
        for(int i=0;i<=60;i++){
            ll x = num1-1LL*num2*i;
            if(x<i){
                return -1;
            }
            if(i>= __builtin_popcountll(x)){
                return i;
            }

        }
        return -1;
    }
};