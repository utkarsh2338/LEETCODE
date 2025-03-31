// #define MOD 1337
// class Solution {
// public:
//     int power(int a, int b){
//         if(b == 0){
//             return 1;
//         }
//         int half = power(a,b/2);
//         int res = half*half;
//         if(b % 2 == 1){
//             return res*a;
//         }
//         return res;
//     }
//     int superPow(int a, vector<int>& b) {
//         int int2 = 0;
//         int n = b.size();
//         for(int mult = 1,i=n-1; mult <= n,i>=1; mult *= 10,i--){
//             int2 += b[i]*mult;
//             i++;
//         }
//         return power(a,int2) % MOD;
//     }
// };
// #define MOD 1337
// class Solution {
// public:
//     int power(int a, int b) {
//         if (b == 0) {
//             return 1;
//         }
//         int half = power(a, b / 2) % MOD;
//         int res = (1LL * half * half) % MOD;  // Prevent overflow
//         if (b % 2 == 1) {
//             res = (1LL * res * a) % MOD;  // Apply modulo at every step
//         }
//         return res;
//     }

//     int superPow(int a, vector<int>& b) {
//         long long int2 = 0;  // Use long long to prevent overflow
//         int n = b.size();
        
//         for (long long mult = 1, i = n - 1; i >= 0; mult = (mult * 10) % (MOD - 1), i--) { // Use MOD-1
//             int2 = (int2 + b[i] * mult) % (MOD - 1); // Keep within MOD-1 to avoid large numbers
//         }

//         return power(a, int2);
//     }
// };


class Solution {
private:
    int solve(int base, int power, int mod) {
        int ans = 1;
        while (power > 0) {
            if (power & 1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            power >>= 1;
        }
        return ans;
    }

public:
    int superPow(int a, vector<int>& b) {
        a%=1337;
        int n = b.size();
        int m = 1140;
        int expi = 0;
        for(int i : b){
            expi = (expi*10+i)%m;
        }
        if (expi == 0) {
            expi = m;
        }
        return solve(a,expi,1337);
    }
};