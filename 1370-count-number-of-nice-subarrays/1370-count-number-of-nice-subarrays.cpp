class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;  // base case: 0 odd numbers seen
        int res = 0, odd = 0;

        for (int num : nums) {
            if (num % 2 == 1) odd++;  // count odd numbers
            if (count.find(odd - k) != count.end()) {
                res += count[odd - k];
            }
            count[odd]++;
        }

        return res;
    }
};
