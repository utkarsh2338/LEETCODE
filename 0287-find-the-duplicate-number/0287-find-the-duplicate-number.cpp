class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];// ek step chalo
        fast = nums[nums[fast]];// do step chalo isko yaha par hhi move karne ka logic ye tha ki agr mai aisa nahi karta toh jo mera cycle detectio ke ;iye mai loop chala raha hu vo ek baar bhi execute nahi hota
        // while loop for detecting cycle
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];// wapas se starting point par aa jao
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};