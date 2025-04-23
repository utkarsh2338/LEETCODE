class Solution {
public:
    int sumOfDigit(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mpp;
        int maxSize = 0;
        int count = 0;
        for(int num = 1;num<=n;num++){
            int digitSum = sumOfDigit(num);
            mpp[digitSum]++;
            if(mpp[digitSum] == maxSize){
                count++;
            }
            else if(mpp[digitSum] > maxSize){
                maxSize = mpp[digitSum];
                count =1;
            }
        }
        return count;
    }
};