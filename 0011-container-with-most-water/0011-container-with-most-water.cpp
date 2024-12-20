class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        int lp = 0;
        int rp = n-1;
        while(lp<rp){
            int wd = rp-lp;
            int ht = min(height[rp],height[lp]);
            int currWater = wd*ht;
            if(height[lp]<height[rp]) lp++;
            else rp--;
            maxWater = max(maxWater,currWater);
        }
        return maxWater;
    }
};