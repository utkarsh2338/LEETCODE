class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_ele = *min_element(nums.begin(),nums.end());
        return min_ele;
    }
};