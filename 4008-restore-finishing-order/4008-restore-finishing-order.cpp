class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size();
        int m = friends.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(friends[j] == order[i]){
                    ans.push_back(friends[j]);
                }
            }
        }
        return ans;
    }
};