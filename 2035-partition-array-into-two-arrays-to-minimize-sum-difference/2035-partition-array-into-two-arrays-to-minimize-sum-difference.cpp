class Solution {
public:

    void generate(vector<int>& nums,int idx,int end,int count,int sum,vector<vector<int>>& sums) {
        if (idx == end) {
            sums[count].push_back(sum);
            return;
        }

        // Don't take nums[idx]
        generate(nums, idx + 1, end,
                 count, sum, sums);

        // Take nums[idx]
        generate(nums, idx + 1, end,
                 count + 1, sum + nums[idx], sums);
    }

    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 2;

        vector<int> left(nums.begin(),nums.begin() + n);

        vector<int> right(nums.begin() + n,nums.end());

        // leftSums[k] = sums obtained by
        // selecting exactly k elements from left
        vector<vector<int>> leftSums(n + 1);
        vector<vector<int>> rightSums(n + 1);

        generate(left, 0, n, 0, 0, leftSums);
        generate(right, 0, n, 0, 0, rightSums);

        // Sort so that we can binary search
        for (int i = 0; i <= n; i++) {
            sort(rightSums[i].begin(),rightSums[i].end());
        }

        int total = accumulate(nums.begin(),nums.end(), 0);

        int ans = INT_MAX;

        // Choose k elements from left
        // and n-k elements from right
        for (int k = 0; k <= n; k++) {
            int remaining = n - k;
            for (int sumLeft : leftSums[k]) {
                double target =(double)total / 2 - sumLeft;
                auto& v = rightSums[remaining];
                auto it = lower_bound(v.begin(),v.end(),target);

                // Candidate 1
                if (it != v.end()) {
                    int sumRight = *it;
                    int sum1 = sumLeft + sumRight;
                    int sum2 = total - sum1;
                    ans = min(ans,abs(sum1 - sum2));
                }

                // Candidate 2: element just before it
                if (it != v.begin()) {
                    --it;
                    int sumRight = *it;
                    int sum1 = sumLeft + sumRight;
                    int sum2 = total - sum1;
                    ans = min(ans,abs(sum1 - sum2));
                }
            }
        }
        return ans;
    }
};