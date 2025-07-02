/************************************************* उत्कर्ष $hukla *****************************************************/
#define ll long long
#define MOD 998244353
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
    int M = 1e9+7;

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        int n = freq.size();
        
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        for(int count = k-1; count >= 0; count--) {
            t[n][count] = 1;
        }

        for(int i = n-1; i >= 0; i--) {

            vector<int> prefix(k+1, 0);
            for(int h = 1; h <= k; h++) {
                prefix[h] = (prefix[h-1] + t[i+1][h-1]) % M;
            }

            for(int count = k-1; count >= 0; count--) {
                
                int l = count + 1;
                int r = count + freq[i];

                if(r+1 > k) {
                    r = k-1;
                }

                if(l <= r) {
                    t[i][count] = (prefix[r+1] - prefix[l] + M) % M;
                }
                
            }
        }

        long long invalidCount = t[0][0];

        return (P - invalidCount + M) % M;
    }
};