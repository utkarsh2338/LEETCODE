class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int s1=m-k+1;
        int s2=n-k+1;
        vector<vector<int>>ans(s1,vector<int>(s2,0));
        for(int i=0;i<s1;i++){
            for(int j=0;j<s2;j++){
                vector<int>vals(k*k);
                int idx=0;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        vals[idx++]=grid[x][y];
                    }
                }
                sort(vals.begin(),vals.end());
                vector<int>distinct;
                distinct.reserve(k*k);
                distinct.push_back(vals[0]);
                for(int t=1;t<vals.size();t++){
                    if(vals[t]!=vals[t-1]){
                        distinct.push_back(vals[t]);
                    }
                }
                if(distinct.size()<=1){
                    ans[i][j]=0; 
                    continue;
                }
                int mini=INT_MAX;
                for(int t=1;t<distinct.size();t++){
                    int dif=distinct[t]-distinct[t-1];
                    if(dif<mini){
                        mini=dif;
                    }
                    if(mini==0) break;
                }
                ans[i][j]=mini;
            }
        }
        return ans;
    }
};