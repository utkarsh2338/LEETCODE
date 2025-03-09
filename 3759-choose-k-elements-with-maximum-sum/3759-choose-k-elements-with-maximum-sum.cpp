class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<int> indices(n);
    vector<long long> result(n, 0);

    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return nums1[a] < nums1[b]; 
    });

    priority_queue<long long, vector<long long>, greater<long long>> minHeap; 
    long long sum = 0;
    int j = 0;

    for (int i = 0; i < n; ++i) {
        int idx = indices[i];

        while (j < i) {
            int idj = indices[j];
            if (nums1[idj] >= nums1[idx]) break; 
            
            minHeap.push(nums2[idj]);
            sum += nums2[idj];

            if ((int)minHeap.size() > k) { 
                sum -= minHeap.top();
                minHeap.pop();
            }
            j++;
        }

        result[idx] = (minHeap.size() > 0) ? sum : 0; 
    }

    return result;
    }
};