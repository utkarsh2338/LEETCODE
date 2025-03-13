class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diffArr(n+1,0);
        int rows = queries.size();
        
        for(int i=0;i<rows;i++){
            diffArr[queries[i][0]] += 1;
            diffArr[queries[i][1] + 1] -= 1;
        } 
        
        for(int i=1;i<diffArr.size();i++){
            diffArr[i] += diffArr[i-1];
        } 
        
        for(int i=0;i<n;i++){
            if(nums[i] > diffArr[i]) return false;
        }
        return true;
    }
};