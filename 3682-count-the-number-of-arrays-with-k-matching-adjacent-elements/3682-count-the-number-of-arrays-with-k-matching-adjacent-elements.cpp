#define MOD 1000000007
class Solution {
public:
    // Har ek element array ka 1 to m me hi lie karega
    // Exactly k indices hain uss array me jo ki arr[i-1] == arr[i] ki condition
    // ko satisfy karenge size hona chahiye n
    long long ncr(int n, int r, vector<int>& factorial,vector<int>& inverseFactorial) {
        // n!*(r)^-1*(n-r)^-1 % MOD
        return ((1LL * factorial[n] * inverseFactorial[n - r]) % MOD * inverseFactorial[r]) % MOD;

    }
    long long power(int x, long long n) { // O(log n)
        long long ans = 1 % MOD;
        while (n > 0) {
            if (n & 1) {
                ans = 1LL * ans * x % MOD;
            }
            x = 1LL * x * x % MOD;
            n >>= 1;
        }
        return ans;
    }

    int countGoodArrays(int n, int m, int k) {
        vector<int> factorial(n + 1, 1);
        factorial[0] = 1;
        factorial[1] = 1;

        for (int i = 2; i <= n; i++) {
            factorial[i] = (1LL*factorial[i - 1] * i) % MOD;
        }
        
        // jaise hamne factorial calculate kiya hai vaise hi mai inverse
        // factorial bhi calculate kar lunga using fermat's little theorm
        vector<int> inverseFactorial(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            inverseFactorial[i] = power(factorial[i], MOD - 2);
        }
        if (k > n - 1) return 0;  // No way to have k equal pairs if we have less than k adjacent pairs

        long long res = ncr(n-1,k,factorial,inverseFactorial);
        res = (res * m)%MOD;
        res = (res * power(m-1,n-k-1)) % MOD;
        return res;
    }
};