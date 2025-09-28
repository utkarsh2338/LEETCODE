class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        long long base = 1;
        int m = n;
        vector<int>ans;
        while(m>0){
            int temp = m%10;
            if(temp != 0) ans.push_back(temp*base);
            m/=10;
            base*=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};