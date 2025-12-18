    /************************************************* उत्कर्ष $hukla *****************************************************/
    #include<bits/stdc++.h>
    using namespace std; 
    #define ll long long
    #define MOD 1000000007
    #define INF 1000000000000000000LL
    #define PB push_back
    #define MP make_pair
    #define f(i, n) for (ll i = 0; i < n; i++)
    typedef vector<ll> VI;
    typedef pair<ll, ll> PII;
    typedef vector<PII> VII;
    typedef vector<VI> VVI;
    typedef map<ll, ll> MPII;
    typedef set<ll> SETI;
    typedef multiset<ll> MSETI;

    // Fast modular exponentiation
    ll power(ll base, ll exp, ll mod = MOD) {
        ll result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    // Precompute factorials
    vector<ll> fact;
    void precompute_factorials(ll n, ll mod = MOD) {
        fact.resize(n + 1);
        fact[0] = 1;
        for (ll i = 1; i <= n; i++)
            fact[i] = (fact[i - 1] * i) % mod;
    }
    ll get_factorial(ll n) {
        return fact[n];
    }

    // Check if prime
    bool isPrime(ll n) {
        if (n < 2) return false;
        for (ll i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    // Smallest prime factor sieve + prime factorization
    vector<ll> spf(100001);
    void build_spf() {
        for (int i = 0; i < 100001; i++) spf[i] = i;
        for (int i = 2; i * i < 100001; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < 100001; j += i)
                    if (spf[j] == j) spf[j] = i;
            }
        }
    }
    vector<ll> primefact(ll n) {
        vector<ll> ans;
        while (n > 1) {
            ans.push_back(spf[n]);
            n /= spf[n];
        }
        return ans;
    }

    // Floor division handling negatives
    ll fdiv(ll x, ll y) {
        if (x >= 0) return x / y;
        return -((-x + y - 1) / y);
    }

    // Check if number has only one non-zero digit
    bool check(int x) {
        int cnt = 0;
        while (x > 0) {
            if (x % 10 != 0) cnt++;
            x /= 10;
        }
        return cnt == 1;
    }
    // check if a number is a power of 2
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
    // Check if a number is a power of 10
    bool isPowerOfTen(int n) {
        if (n <= 0) return false;   
        while (n % 10 == 0) {
            n /= 10;
        }       
        return n == 1;
    }
    // Check if a number is a power of 5
    bool isPowerOfFive(int n) {
        if (n <= 0) return false;   
        while (n % 5 == 0) {
            n /= 5;
        }   
        return n == 1;
    }
    // Check if a number is a power of 3
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        ll max1 = 0;
        for(int i=0;i<n;i++){
            max1 += (ll)strategy[i]*prices[i];
        }
        int l_index=k/2;
        vector<ll>pP(n+1,0),pS(n+1,0);
        for(int i=0;i<n;i++){
            pP[i+1] = pP[i]+(ll)prices[i];
            pS[i+1] = pS[i]+(ll)strategy[i]*prices[i];
        }
        ll bestDiff = LLONG_MIN;
        for(int l=0;l+k<=n;l++){
            ll sumOfPInSecond = pP[l+k]-pP[l+l_index];
            ll sumOfSInWhole = pS[l+k] - pS[l];
            ll diff = sumOfPInSecond - sumOfSInWhole;
            if(diff > bestDiff){
                bestDiff = diff;
            }
        }
        if(bestDiff < 0) bestDiff =0;
        return max1+bestDiff;
    }
};