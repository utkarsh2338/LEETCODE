class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k == 0) return ans;

        int n1 = nums1.size(), n2 = nums2.size();

        // min-heap: {sum, i, j}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // initialize: pair nums1[i] with nums2[0]
        for (int i = 0; i < n1 && i < k; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int sum = cur[0], i = cur[1], j = cur[2];

            ans.push_back({nums1[i], nums2[j]});

            // push next pair: (i, j+1)
            if (j + 1 < n2) {
                pq.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }

        return ans;
    }
};