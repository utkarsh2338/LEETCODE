class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>freeArray;
        freeArray.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }
        freeArray.push_back(eventTime - endTime[n-1]);
        int i =0,j=0;
        int maxSum = 0;
        int sum = 0;
        while(j<freeArray.size()){
            sum += freeArray[j];
            if( i<n && j-i+1 > k+1){
                sum -= freeArray[i];
                i++;
            }
            maxSum = max(maxSum,sum);
            j++;
        }
        return maxSum;
    }
};