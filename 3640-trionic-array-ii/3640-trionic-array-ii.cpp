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
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
    ll n = nums.size(), res = LLONG_MIN, psum = nums[0];
    for (int l = 0, p = 0, q = 0, r = 1; r < nums.size(); ++r) {
        psum += nums[r];
        if (nums[r - 1] == nums[r]) {
            l = r;
            psum = nums[r];
        }
        else if (nums[r - 1] > nums[r]) {
            if (r > 1 && nums[r - 2] < nums[r - 1]) { // flip
                p = r - 1;
                while (l < q)
                    psum -= nums[l++];    
                while (l + 1 < p && nums[l] < 0)
                    psum -= nums[l++];
            }
        }
        else {
            if (r > 1 && nums[r - 2] > nums[r - 1]) // flip
                q = r - 1;
            if (l < p && p < q)
                res = max(res, psum);
        }
    }
    return res;
}
};