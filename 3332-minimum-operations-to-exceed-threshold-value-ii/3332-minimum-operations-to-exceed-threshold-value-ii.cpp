class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ops = 0;
        priority_queue<long,vector<long>,greater<long>>pq(nums.begin(),nums.end());
        while(pq.top() < k){
            long ele1 = pq.top();
            pq.pop();
            long ele2 = pq.top();
            pq.pop();
            pq.push(min(ele1,ele2) * 2 + max(ele1,ele2));
            ops++;
        }
        return ops;
    }
};