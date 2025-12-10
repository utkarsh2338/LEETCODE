using ll = long long;
const int MOD = 1e9+7;
class Solution {
public:
    ll factorial(ll n){
        if(n<=1) return 1;
        return n*factorial(n-1); 
    }
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int root = complexity[0];
        for(int i=1;i<n;i++){
            if(complexity[i] <= root) return 0;
        }
        ll fact = 1;
        for (int i = 2; i < n; i++) {
            fact = (fact * i) % MOD;
        }
        return (int)fact;
    }
};