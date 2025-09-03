class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0] == b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int pairCount = 0;
        int n = points.size();
        for(int i=0;i<n;i++){
            int upperY = points[i][1];
            int lowerLimit = INT_MIN;
            for(int j=i+1;j<n;j++){
                int currY = points[j][1];

                if(currY <= upperY && currY > lowerLimit){
                    pairCount++;
                    lowerLimit = currY;
                    if(currY == upperY) break;
                }
            }
        }
        return pairCount;
    }
};