class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int binarySearch(vector<vector<int>>& events, int endTime) {
        int l = 0;
        int r = n - 1;
        int result = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] > endTime) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& events, int i, int count) {
        if (count == 2 || i >= n) {
            return 0;
        }
        if (memo[i][count] != -1) {
            return memo[i][count];
        }

        int nextValidEventIdx = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextValidEventIdx, count + 1);
        int not_take = solve(events, i + 1, count);
        return memo[i][count] = max(take, not_take);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end()); // Sort events by start time
        memo.assign(n, vector<int>(3, -1)); // Initialize memoization table
        return solve(events, 0, 0);
    }
};