#define ll long long
class Solution {
private:
    vector<int> mpp, a;

    ll perm(int n, int right, ll ch) {
        if (right > n) return 0;
        if (right > n - right) right = n - right;
        ll ans = 1;
        for (int it = 1; it <= right; it++) {
            __int128 temp = (__int128)ans * (n - right + it);
            temp /= it;
            if (temp >= ch) temp = ch;
            ans = (ll)temp;
        }
        return ans;
    }

    ll NCR(int tot, ll ch) {
        ll tareeke = 1;
        int remainder = tot;
        for (int it = 0; it < 26; it++) {
            int count = a[it];
            if (count == 0) continue;
            ll cur = perm(remainder, count, ch);
            __int128 product = (__int128)tareeke * cur;
            if (product >= ch) product = ch;
            tareeke = (ll)product;
            remainder -= count;
        }
        return tareeke;
    }

public:
    string smallestPalindrome(string s, int k) {
        int len = s.length();
        int half = len / 2;

        mpp.assign(26, 0);
        a.assign(26, 0);

        for (char x : s)
            mpp[x - 'a']++;

        char mid = ' ';
        for (int it = 0; it < 26; it++) {
            a[it] = mpp[it] / 2;
            if (mpp[it] % 2 == 1 && mid == ' ')
                mid = 'a' + it;
        }

        ll tot = NCR(half, k);
        if (k > tot) return "";

        string left = "";
        for (int pos = 0; pos < half; pos++) {
            for (int it = 0; it < 26; it++) {
                if (a[it] > 0) {
                    a[it]--;
                    ll tareeke = NCR(half - pos - 1, k);
                    if (tareeke < k) {
                        k -= tareeke;
                        a[it]++;
                    } else {
                        left.push_back('a' + it);
                        break;
                    }
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid != ' ')
            left += mid;

        return left + right;
    }
};
