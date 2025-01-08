class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, rightSum = 0;
        int maxSum = 0;
        int n = cardPoints.size();

        // Calculate the initial sum of the first `k` cards (leftSum)
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        maxSum = leftSum;

        // Shift the window by taking cards from the right instead of the left
        for (int i = 0; i < k; i++) {
            leftSum -= cardPoints[k - 1 - i]; // Remove one card from the left
            rightSum += cardPoints[n - 1 - i]; // Add one card from the right
            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};
