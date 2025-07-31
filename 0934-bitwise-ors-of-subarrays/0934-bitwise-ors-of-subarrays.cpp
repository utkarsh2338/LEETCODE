class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int>resOrs;
        unordered_set<int>currOrs;
        for(int x: arr){
            unordered_set<int>nextOrs;
            nextOrs.insert(x);
            for(int y: currOrs){
                nextOrs.insert(x|y);
            }
            resOrs.insert(nextOrs.begin(),nextOrs.end());
            currOrs = nextOrs;
        }
        return resOrs.size();
    }
};