const int N = 1e5;
int pa[N], deg[N], q[N];

class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        memset(pa,0,sizeof(int)*n),memset(deg,0,sizeof(int)*n);
        deg[0] = 2;
        for(auto& e:edges){
            int a = e[0],b= e[1];
            deg[a]++,deg[b]++;
            pa[a] ^= b,pa[b] ^= a;
        }
        for(int i=0;i<n;i++) good[i] = (good[i] << 1) -1;
        int qi = 0;
        for(int s=0;s<n;s++){
            for(int i=s,p;deg[i] == 1;pa[p] ^= i,--deg[p],i=p){
                q[qi++] = i;
                deg[i] = 0;
                p = pa[i];
                if(good[i] > 0) good[p] += good[i];
            }
        }
        while(qi--){
            int i = q[qi];
            good[i] += max(0,good[pa[i]]-max(0,good[i]));
        }
        return good;
    }
};