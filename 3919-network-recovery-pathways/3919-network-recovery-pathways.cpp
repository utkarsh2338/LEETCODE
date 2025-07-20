/************************************************* उत्कर्ष $hukla
 * *****************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define INF 1000000000000000000LL
#define PB push_back
#define MP make_pair
#define f(i, n) for (ll i = 0; i < n; i++)
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef vector<P> VII;
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
ll get_factorial(ll n) { return fact[n]; }

// Check if prime
bool isPrime(ll n) {
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Smallest prime factor sieve + prime factorization
vector<ll> spf(100001);
void build_spf() {
    for (int i = 0; i < 100001; i++)
        spf[i] = i;
    for (int i = 2; i * i < 100001; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < 100001; j += i)
                if (spf[j] == j)
                    spf[j] = i;
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
    if (x >= 0)
        return x / y;
    return -((-x + y - 1) / y);
}

// Check if number has only one non-zero digit
bool check(int x) {
    int cnt = 0;
    while (x > 0) {
        if (x % 10 != 0)
            cnt++;
        x /= 10;
    }
    return cnt == 1;
}

ll dijkstra(int src, int target, vector<vector<P>>& adj, int n) {
    ll maxi = LLONG_MAX / 4;
    VI dist(n, maxi);
    dist[src] = 0;
    priority_queue<P, VII, greater<>> pq;
    pq.emplace(0, src);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        if (u == target)
            return d;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return maxi;
}

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        ll low = 0, high = 1e9, best = -1;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            vector<vector<P>> adj(n);
            for (auto& e : edges) {
                int u = e[0], v = e[1], c = e[2];
                if (c >= mid && online[u] && online[v]) {
                    adj[u].emplace_back(v, c);
                }
            }
            ll dist = dijkstra(0, n - 1, adj, n);
            if (dist <= k){
                best = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
                
        }
        return best;
    }
};