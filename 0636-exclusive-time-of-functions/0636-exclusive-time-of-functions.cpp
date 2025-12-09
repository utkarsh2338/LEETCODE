class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>res(n,0);
        stack<int>st;
        int prev = 0;
        for(auto& log: logs){
            int pos1 = log.find(':');
            int pos2 = log.find(":",pos1+1);

            int id = stoi(log.substr(0,pos1));
            string type = log.substr(pos1+1,pos2-pos1-1);
            int time = stoi(log.substr(pos2+1));

            if(type == "start"){
                if(!st.empty()){
                    res[st.top()] += time-prev;
                }
                st.push(id);
                prev = time;
            }
            else{
                res[st.top()] += time-prev+1;
                st.pop();
                prev = time+1;
            }
        }
        return res;
    }
};