class Solution {
public:
    typedef pair<int,int> P;// duration time and index
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int,3>>sortedTasks;// kab start hoga kitne time tak chalega aur index
        // lets fill the sorted task
        for(int i=0;i<n;i++){
            int startTime = tasks[i][0];
            int processingTime = tasks[i][1];
            sortedTasks.push_back({startTime,processingTime,i});
        }
        // sort it according to the start time
        sort(sortedTasks.begin(),sortedTasks.end());

        vector<int> ans;

        long long currTime = 0;
        int idx = 0;

        priority_queue<P,vector<P>,greater<>>pq;


        while(idx < n || ! pq.empty()){
            if(pq.empty() && currTime < sortedTasks[idx][0]){
                    currTime = sortedTasks[idx][0];
            }
            while(idx < n && sortedTasks[idx][0] <= currTime){
                pq.push({sortedTasks[idx][1],sortedTasks[idx][2]});
                idx++;
            }
            pair<int,int>currTask = pq.top();
            pq.pop();

            currTime += currTask.first;
            ans.push_back(currTask.second);
        } 
        return ans;
    }
};