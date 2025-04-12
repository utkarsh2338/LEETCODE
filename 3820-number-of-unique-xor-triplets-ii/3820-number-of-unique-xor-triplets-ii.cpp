#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_set<long long> xorPairs;
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                xorPairs.insert((long long)(nums[i]) ^ nums[j]);

        vector<bool> vis((int)1e5, false);
        int cnt = 0;
        for (auto it : xorPairs) {
            for (int nt : nums) {
                int x = (int)(it ^ nt);
                if (x < (int)vis.size() && !vis[x]) {
                    cnt++;
                    vis[x] = true;
                }
            }
        }

        return cnt;
    }
};
