class Solution {
public:
    long long countNodes(long long prefix, long long n) {
        long long count = 0, curr = prefix, next = prefix + 1;
        while (curr <= n) {
            count += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1; 

        while (k > 0) {
            long long count = countNodes(curr, n);
            if (count <= k) {
                k -= count;
                curr++; 
            } else {
                curr *= 10; // go deeper
                k -= 1; 
            }
        }

        return curr;
    }
};
