#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    int n;

    void solve(int idx, int sum, vector<int>& candidates, int target, vector<int>& temp) {
        // Base case: if the sum equals the target
        if (sum == target) {
            result.push_back(temp);
            return;
        }

        // Base case: if the index exceeds bounds or the sum exceeds the target
        if (idx >= n || sum > target) {
            return;
        }

        // Include the current candidate
        temp.push_back(candidates[idx]);
        solve(idx, sum + candidates[idx], candidates, target, temp);
        temp.pop_back();

        // Exclude the current candidate and move to the next index
        solve(idx + 1, sum, candidates, target, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        n = candidates.size();
        result.clear();  // Ensure result is cleared for multiple calls
        solve(0, 0, candidates, target, temp);
        return result;
    }
};
