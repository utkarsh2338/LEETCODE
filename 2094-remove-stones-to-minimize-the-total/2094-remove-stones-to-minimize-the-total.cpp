class Solution {
public:
    int minStoneSum(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        while(k-- && !pq.empty()){
            int x = pq.top();
            pq.pop();
            int ele = x- x/2;
            pq.push(ele);
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
}; 