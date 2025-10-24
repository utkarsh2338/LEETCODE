class Solution {
public:
    bool isBalanced(int num){
        vector<int>freq(10);
        while(num>0){
            int digit = num%10;// last digit
            freq[digit]++;
            num /= 10;
        }
        for(int i=0;i<10;i++){
            if(freq[i] != 0 && freq[i] != i){
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int num = n+1;num <= 1224444;num++){
            if(isBalanced(num)){
                return num;
            }
        }
        return -1;
    }
};