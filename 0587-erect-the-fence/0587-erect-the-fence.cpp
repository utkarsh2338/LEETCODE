class Solution {
public:
    int findEquationVal(pair<int,int>&P1,pair<int,int>&P2,pair<int,int>P3){
        int x1 = P1.first;
        int x2 = P2.first;
        int x3 = P3.first;

        int y1 = P1.second;
        int y2 = P2.second;
        int y3 = P3.second;
        return (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end());
        vector<vector<int>> res;
        deque<pair<int,int>>upper;// aur ye honge points ke deques
        deque<pair<int,int>>lower;

        for(auto& point: trees){
            int l = lower.size();
            int u = upper.size();
            // lower ka check karenge pahle
            while(l >= 2 && findEquationVal(lower[l-2],lower[l-1],{point[0],point[1]}) < 0){
                l--;
                lower.pop_back();
            }
            // fir ham check karenge upper ka 
            while(u >= 2 && findEquationVal(upper[u-2],upper[u-1],{point[0],point[1]}) > 0){
                u--;
                upper.pop_back();
            }
            upper.push_back({point[0],point[1]});
            lower.push_back({point[0],point[1]});
        }
        set<pair<int,int>>st;
        for(auto& it: upper){
            st.insert(it);
        }
        for(auto& it: lower){
            st.insert(it);
        }
        for(auto& it : st){
            res.push_back({it.first,it.second});
        }
        return res;
    }
};