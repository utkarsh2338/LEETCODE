class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if(n==2) return 2;
        int even = 0,odd=0;
        int alter = 0;
        for(int i=0;i<n;i++){
            if(nums[i]%2 == 0){
                even++;
            }
            else{
                odd++;
            }
        }
        for(int i=0;i<n-1;i++){
            if(nums[i] % 2 == 0 && nums[i+1] % 2 != 0){
                alter++;
            }
            else if(nums[i]%2 !=0 && nums[i+1]%2 ==0){
                alter++;
            }
        }
        return max({even,odd,alter+1});
    }
};