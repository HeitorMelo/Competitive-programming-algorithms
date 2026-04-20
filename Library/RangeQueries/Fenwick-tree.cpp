#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE

struct Fenwick {
    int n;
    int max_pow; // for searching only
    vector<ll> bit;

    Fenwick() {}
    Fenwick(int _n): n(_n), bit(_n + 1, 0) {
        max_pow = 1 << (31 - __builtin_clz(n));
    }

    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    ll pref_sum(int idx) const {
        ll ans = 0;
        for (; idx > 0; idx -= idx & -idx) {
            ans += bit[idx];
        }
        return ans;
    }

    ll range_sum(int l, int r) const {
        if (l > r) return 0;
        return pref_sum(r) - pref_sum(l - 1);
    }

    int end() const { return n + 1; }

    int lower_bound(ll k) {
        if (k > pref_sum(n)) return end();
        if (k <= 0) return 0;
        int pos = 0;
        
        for (int i = max_pow; i > 0; i >>= 1) {
            if (pos + i <= n && bit[pos + i] < k) {
                pos += i;
                k -= bit[pos];
            }
        }
        return pos + 1;
    }

    int upper_bound(ll k) {
        return lower_bound(k + 1LL);
    }
};
