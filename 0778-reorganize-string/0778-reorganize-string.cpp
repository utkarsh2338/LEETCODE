class Solution {
public:
    typedef pair<int,char> P;
    string reorganizeString(string s) {
        int n = s.length();
        string res = "";
        vector<int>mpp(26,0);
        for(auto& it: s){
            mpp[it - 'a']++;

            if(mpp[it - 'a'] > (n+1)/2) return "";
        }
        priority_queue<P,vector<P>>pq;
        for(char ch = 'a';ch <= 'z';ch++){
            if(mpp[ch-'a'] > 0){
                pq.push({mpp[ch-'a'],ch});
            }
        }

        while(pq.size() >= 2){
            auto p1 = pq.top();
            pq.pop();

            auto p2 = pq.top();
            pq.pop();

            res.push_back(p1.second);
            p1.first--;// ek baar le liya toh freq ko minus bhi kar do

            res.push_back(p2.second);
            p2.first--;

            if(p1.first > 0){
                pq.push(p1);
            }

            if(p2.first > 0){
                pq.push(p2);
            }
        }
        if(!pq.empty()){
            res.push_back(pq.top().second);
        }
        return res;
    }
};