class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        int i = 0, res = 0;
        unordered_map<int, int> freq;

        for (int j = 0; j < nums.size(); j++) {
            if (freq[nums[j]] == 0) {
                k--;  // new unique element
            }
            freq[nums[j]]++;

            while (k < 0) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    k++;
                }
                i++;
            }

            res += j - i + 1;
        }

        return res;
    }
};
