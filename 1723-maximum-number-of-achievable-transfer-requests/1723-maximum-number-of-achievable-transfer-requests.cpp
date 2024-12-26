class Solution {
public:
    int m;
    int result = INT_MIN;
    void solve(int idx, int count,int n, vector<int>& buildings, vector<vector<int>>& requests){
        // base case 
        if(idx>=m){
            bool allZero = true;
            for(auto& x: buildings){
                if(x!=0){
                    allZero = false;
                    break;
                }
            }
            if(allZero == true){
                result = max(result,count);
            }
            return;
        }
        int from = requests[idx][0];
        int to = requests[idx][1];
        buildings[from] --;
        buildings[to] ++;
        solve(idx+1,count+1,n,buildings,requests);
        buildings[from] ++;
        buildings[to] --;
        solve(idx+1,count,n,buildings,requests);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m = requests.size();
        // ek vector bana lete hain jo ki store karega buildings
        vector<int>buildings(n,0);
        solve(0,0,n,buildings,requests);
        return result;
    }
};