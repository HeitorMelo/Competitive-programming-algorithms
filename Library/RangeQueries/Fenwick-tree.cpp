#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick() {}
    Fenwick(int n): n(n), bit(n + 1, 0) {}

    // add value to index idx (1-indexed)
    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    // sum of [1..idx]
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
};
