class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long cnt = 0;
        int i = 0, j = 0, n = nums.size();
        // unordered_map<int,int>mpp;
        int maxEle = *max_element(nums.begin(), nums.end());
        int freq = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == maxEle) {
                freq++;
            }

            // yaha par maine nikal liya kitne baar ye maxEle aa raha hai
            while (freq >= k) {
                // count of maxElement >= k --> cnt++;
                // mpp[nums[j]]++;
                cnt += (n - j);
                // if(mpp[nums[j]] == maxEle){
                if (nums[i] == maxEle) {
                    freq--;
                }
                i++;
            }
        }
        return cnt;
    }
};