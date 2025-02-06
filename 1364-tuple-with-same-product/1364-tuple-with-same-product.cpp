class Solution {
public:
    int tupleSameProduct(std::vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size();
        
        // Count the frequency of each product of pairs
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }
        
        int result = 0;
        
        // Calculate the number of valid tuples
        for (const auto& [product, count] : productCount) {
            if (count >= 2) {
                result += count * (count - 1) * 4; // Each pair can form 4 tuples
            }
        }
        
        return result;
    }
};