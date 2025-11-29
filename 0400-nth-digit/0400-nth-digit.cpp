using ll = long long;
class Solution {
public:
    int findNthDigit(int n) {
        ll len = 1;
        ll count = 9;
        ll start = 1;
        while(n > len*count){
            n -= len*count;
            len++;
            count *= 10;
            start *= 10;
        }
        start += (n-1)/len;
        string s = to_string(start);
        return s[(n-1)%len]-'0';
    }
};