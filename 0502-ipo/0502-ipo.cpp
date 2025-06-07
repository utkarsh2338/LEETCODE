class Solution {
public:
    typedef pair<int, int> P;
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        // sort agr mai kar dumga capital ko toh mujhe compare karke choose
        // karna aasan hoga
        int n = profits.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({capital[i], profits[i]});
        }
        sort(a.begin(), a.end());
        priority_queue<int> pq;
        int i = 0;
        while (k--) {
            while (i < n && a[i].first <= w) {
                // yes i can buy
                pq.push(a[i].second);
                i++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else
                break;
        }

        return w;
    }
};