#define ll long long
class Solution {
public:
    string convertBaseK(long long n, int k) {
        string res = "";
        while (n > 0) {
            res += (char)(n % k + '0');
            n /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isPalindrome(const string& st) {
        int i = 0, j = st.size() - 1;
        while (i <= j) {
            if (st[i] != st[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        ll cnt = 0, sum = 0;

        for (int len = 1; cnt < n; len++) {
            for (int half = pow(10, (len - 1) / 2); cnt < n && half < pow(10, (len + 1) / 2); half++) {
                string s = to_string(half);
                string rev = s;
                reverse(rev.begin(), rev.end());

                string full = s + (len % 2 ? rev.substr(1) : rev); 
                ll val = stoll(full);

                string baseK = convertBaseK(val, k);
                if (isPalindrome(baseK)) {
                    sum += val;
                    cnt++;
                }
            }
        }

        return sum;
    }
};
