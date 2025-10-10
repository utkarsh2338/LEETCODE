class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxEnergy = INT_MIN;
        for(int i=n-1;i>=n-k;i--){
            int sum = 0;
            for(int j=i;j>=0;j-=k){
                sum += energy[j];
                maxEnergy = max(maxEnergy,sum);
            }  
        }
        return maxEnergy;
    }
};