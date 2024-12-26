class Solution {
public:
    int n;
    int result = INT_MAX;

    void solve(int idx,vector<int>& children,vector<int>& cookies,int k){
        if(idx>=n){
            // maximum find kar lo
            int unfairness = *max_element(begin(children),end(children));
            result = min(result,unfairness);
            return;
        }
        int cookie = cookies[idx];
        for(int i=0;i<k;i++){
            // sabse pahle ek bacche ko cookie de do 
            children[i] += cookie;
            // fir function ko call kar do or explore kar do
            solve(idx+1,children,cookies,k);
            // ab uss bacche se cookie wapas lelo
            children[i] -= cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int>children(k,0);
        solve(0,children,cookies,k);
        return result;
    }
};