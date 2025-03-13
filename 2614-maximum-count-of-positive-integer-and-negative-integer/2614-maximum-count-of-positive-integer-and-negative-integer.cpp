class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto lambdaP = [](int num) { return num > 0; };
        auto lambdaN = [](int num) { return num < 0; };
        int P = count_if(begin(nums), end(nums), lambdaP);
        int N = count_if(begin(nums), end(nums), lambdaN);
        return max(P, N);
    }
};