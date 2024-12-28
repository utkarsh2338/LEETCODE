class Solution {
public:
    int n;
    int result = INT_MAX;
    vector<int>resultScore;
    void solve(int score,vector<int>& perm,vector<int>& nums,vector<bool>& visited){
        // base case 
        if(score>result){
            return;
        }
        if(perm.size() == n){
            score += abs(perm[perm.size()-1]-nums[perm[0]]);
            if(result>score){
                result = score;
                resultScore= perm;
            }
            return;
        }
        // another base case for handling the edge cases
        // now the main function of backtracking
        
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                perm.push_back(i); 
                int s = perm.size();
                solve(score + abs(perm[s-2] - nums[perm[s-1]]), perm, nums, visited);
                visited[i] = false;
                perm.pop_back();
        }
        }
    }
    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();
        vector<bool>visited(n,false);// for storing the different permutations of the given arrray nums
        vector<int>perm={0};
        visited[0] = true;
        solve(0,perm,nums,visited);
        return resultScore;
    }
};