class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnPrice = INT_MAX;
        int mxProfit = 0;
        for(auto&price : prices){
            if(price < mnPrice){
                mnPrice = price;
            }
            if(price - mnPrice > mxProfit){
                mxProfit = price-mnPrice;
            }
        }
        return mxProfit;
    }
};