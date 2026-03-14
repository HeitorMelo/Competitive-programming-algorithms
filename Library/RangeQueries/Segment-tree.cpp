#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
const ll INF = (ll)4e18; //LATEX_IGNORED_LINE

struct SegTreeMin {
    int n;
    vector<ll> st;

    SegTreeMin() {}
    SegTreeMin(const vector<ll>& a) { init(a); }

    void init(const vector<ll>& a) {
        n = (int)a.size();
        st.assign(4 * n + 5, INF);
        build(1, 0, n - 1, a);
    }

    void build(int p, int l, int r, const vector<ll>& a) {
        if (l == r) {
            st[p] = a[l];
            return;
        }

        int m = (l + r) / 2;
        build(2 * p, l, m, a);
        build(2 * p + 1, m + 1, r, a);
        st[p] = min(st[2 * p], st[2 * p + 1]);
    }

    ll query(int p, int l, int r, int i, int j) {
        if (j < l || r < i) return INF;
        if (i <= l && r <= j) return st[p];

        int m = (l + r) / 2;
        return min(query(2 * p, l, m, i, j), query(2 * p + 1, m + 1, r, i, j));
    }

    void update(int p, int l, int r, int idx, ll val) {
        if (l == r) {
            st[p] = val;
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m) update(2 * p, l, m, idx, val);
        else update(2 * p + 1, m + 1, r, idx, val);

        st[p] = min(st[2 * p], st[2 * p + 1]);
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(int idx, ll val) {
        update(1, 0, n - 1, idx, val);
    }
};
