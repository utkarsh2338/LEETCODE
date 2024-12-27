class Solution {
public:
    vector<vector<int>> result;
    void solve(int idx, int sum, int k, int n, vector<int>& temp,
               vector<int>& numbers) {
        // base case
        if (sum == n && temp.size() == k) {
            result.push_back(temp);
            return;
        }
        if (sum > n || temp.size() > k) {
            return;
        }
        // temp.push_back(numbers[idx]);// taken the first number
        // solve(idx+1,sum + numbers[idx] , k,n,temp,numbers);// exploring the
        // function after adding temp.pop_back();// rejecting the numbers
        // solve(idx,sum,k,n,temp,numbers);
        for (int i = idx; i < numbers.size(); i++) {
            temp.push_back(numbers[i]); // Take the number
            solve(i + 1, sum + numbers[i], k, n, temp,
                  numbers);  // Recurse with next index
            temp.pop_back(); // Backtrack
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        solve(0, 0, k, n, temp, numbers);
        return result;
    }
};