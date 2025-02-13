class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(char& ch : s){
            mpp[ch]++;
        }
        using p = pair<int,char>;
        priority_queue<p>pq;
        for(auto& it: mpp){
            pq.push({it.second,it.first});
        }
        string result;
        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            result.append(freq,ch);
        }
        return result;
    }
};