class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0;
        int equal = 0;
        for(int& num: nums){
            if(num<pivot){
                less++;
            }
            else if(num == pivot){
                equal++;
            }
        }
int n = nums.size();
        vector<int>ans(n);
        int lessI = 0;
        int equalI = less;
        int greaterI = less + equal;
        for(int i=0;i<n;i++){
            int num = nums[i];
            if(num<pivot){
                ans[lessI] = num;
                lessI++;
            }
            else if(num > pivot){
                ans[greaterI] = num;
                greaterI++;
            }
            else{
                ans[equalI] = num;
                equalI++;
            }
        }
        return ans;
    }
};