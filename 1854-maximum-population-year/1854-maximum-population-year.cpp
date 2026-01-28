class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>>events;

        for(auto log: logs){
            events.push_back({log[0],+1});
            events.push_back({log[1],-1});
        }
        sort(events.begin(),events.end());

        int cnt = 0;
        int maxCount = 0;
        int minYear =  2050;
        for(auto e: events){
            cnt += e.second;
            if(cnt > maxCount){
                maxCount = cnt;
                minYear = e.first;
            }
        }
        return minYear;
    }
};