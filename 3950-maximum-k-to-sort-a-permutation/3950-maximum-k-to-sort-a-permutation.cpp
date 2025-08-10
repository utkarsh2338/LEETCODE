class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<bool>visited(n,false);
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            int currAnd = i;
            int curr = nums[i];
            int size = 1;
            visited[i] = true;
            while(curr != i){
                visited[curr] = true;
                currAnd &= curr;
                curr = nums[curr];
                size++;
            }
            if(size >= 2){
                ans = min(ans,currAnd);
            }
        }
        return ans == INT_MAX ? 0:ans;

    }
};