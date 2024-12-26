// class Solution {
// public:
//     vector<vector<int>> result;  // To store the resulting combinations
//     int n;  // Size of the input array

//     void solve(int idx, int sum, vector<int>& candidates, int target, vector<int>& temp) {
//         // Base case: if the current sum matches the target, add the combination to the result
//         if (sum == target) {
//             result.push_back(temp);
//             return;
//         }

//         // Iterate over the candidates starting from the current index
//         for (int i = idx; i < n && target >= candidates[i]; ++i) {
//             // Skip duplicates: process a number only if it's the first occurrence or 
//             // if it hasn't been considered in the current recursive level
//             if (i == idx || candidates[i] != candidates[i-1]) {
//                 temp.push_back(candidates[i]);  // Include the current number
//                 solve(i + 1, sum + candidates[i], candidates, target, temp);  // Recurse for the next index
//                 temp.pop_back();  // Backtrack to explore other combinations
//             }
//         }
//     }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         n = candidates.size();
//         vector<int> temp;  // Temporary vector to store the current combination
//         sort(candidates.begin(), candidates.end());  // Sort the array to handle duplicates
//         solve(0, 0, candidates, target, temp);  // Start the backtracking process
//         return result;
//     }
// };


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        combination2(result, combination, candidates, target, 0);
        return result;
    }
    void combination2(vector<vector<int>> &res, vector<int> &combination,
                      vector<int> &candidates, int target, int index) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = index; i < candidates.size() && target >= candidates[i];
             ++i) {
            if (i == index || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                combination2(res, combination, candidates,
                             target - candidates[i], i + 1);
                combination.pop_back();
            }
        }
    }
};
