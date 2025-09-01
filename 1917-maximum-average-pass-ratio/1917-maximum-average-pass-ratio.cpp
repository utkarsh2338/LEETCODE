class Solution {
public:
    #define P pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<P>pq; // {max-delta,idx}
        int n = classes.size();
        for(int i=0;i<n;i++){
            double currPr = (double)classes[i][0]/classes[i][1];
            double newPr = (double)(classes[i][0] +1)/(classes[i][1] + 1);
            double delta = newPr - currPr;
            pq.push({delta,i});
        }
        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();
            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0] ++;
            classes[idx][1] ++;  
            double current_PR = (double)classes[idx][0] / classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);        
            delta = new_PR - current_PR;
            pq.push({delta,idx});           
        }
        double result = 0.0;
        for(int i=0;i<n;i++){
            result += (double)classes[i][0]/classes[i][1];
        }
        return result/n;
    }
};