class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return n;
        int res = 0;
        for(int i=0;i<n;i++){ // pahla point hai ye hamara P1(x1,y1)
            for(int j=i+1;j<n;j++){ // ye hai hamara dusra wala point P2(x2,y2)
            int count = 2;
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                for(int k=0;k<n;k++){ // teesra point
                    if(k!=i && k!=j){
                    int dx_ = points[k][0] - points[i][0];
                    int dy_ = points[k][1] - points[i][1];
                    if(dy*dx_ == dx*dy_) count++;
                }
                
            }
        res = max(res,count);
        }
        }
        return res;
    }
};