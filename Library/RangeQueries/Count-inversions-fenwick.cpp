#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n): n(n), bit(n + 1, 0) {}

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
};

ll count_inversions_fenwick(vector<int> a) {
    if (a.empty()) return 0;

    vector<int> comp = a;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    int m = (int)comp.size();
    Fenwick fw(m);

    ll inv = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int x = (int)(lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin()) + 1;
        inv += fw.pref_sum(x - 1);
        fw.add(x, 1);
    }

    return inv;
}
