class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int cnt = 1;
        vector<int>res;
        for(int i=1;i<=n;i++){
            res.push_back(cnt);
            if(cnt*10 <= n){
                cnt *= 10;// go deeper
            }
            else{
                if(cnt >= n){
                    cnt /= 10;
                }
                cnt++;
                while(cnt % 10 == 0) cnt /= 10;
            }
        }
        return res;
    }
};