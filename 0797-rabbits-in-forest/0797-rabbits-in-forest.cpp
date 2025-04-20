class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int,int>mpp;
        for(auto& it: answers){
            mpp[it]++;
        }
        for(auto& it: mpp){
            int x = it.first;
            int groupSize = it.first+1;
            int count = it.second;
            int groups = ceil((double)count/groupSize);
            ans += groups * (x+1);
        }
        return ans;
    }
};