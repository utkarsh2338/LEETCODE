class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>zeroes(n);
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j = n-1;j>=0 && grid[i][j] == 0;j--) cnt++;
            zeroes[i] = cnt;
        }
        int swaps = 0;
        for(int i=0;i<n;i++){
            int needed = n-i-1;
            int j = i;
            while(j<n && zeroes[j] < needed) j++;
            if(j==n) return -1;
            while(j>i){
                swap(zeroes[j],zeroes[j-1]);
                j--;
                swaps++;
            }
        }
        return swaps;
    }
};