class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int maxCost = *max_element(costs.begin(),costs.end());
        vector<int>freq(maxCost+1,0);
        for(auto& it: costs){
            freq[it]++;
        }
        int ans = 0;
        for(int cost =1;cost<=maxCost;cost++){
            if(freq[cost] == 0) continue;

            int canBuy = min(freq[cost],coins/cost);
            ans += canBuy;
            coins -= canBuy*cost;
            if(coins < cost){
                break;
            }
        }
        return ans;
    }
};