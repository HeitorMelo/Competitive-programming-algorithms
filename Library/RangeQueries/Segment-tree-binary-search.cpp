#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE

struct SegTreeMax {
    int n;
    vector<ll> st;

    SegTreeMax(const vector<ll>& a) {
        n = (int)a.size();
        st.assign(4 * n + 5, 0);
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
        st[p] = max(st[2 * p], st[2 * p + 1]);
    }

    void update(int p, int l, int r, int idx, ll val) {
        if (l == r) {
            st[p] = val;
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m) update(2 * p, l, m, idx, val);
        else update(2 * p + 1, m + 1, r, idx, val);

        st[p] = max(st[2 * p], st[2 * p + 1]);
    }

    // first index with value >= k, or -1 if it does not exist
    int first_ge(int p, int l, int r, ll k) const {
        if (st[p] < k) return -1;
        if (l == r) return l;

        int m = (l + r) / 2;
        if (st[2 * p] >= k) return first_ge(2 * p, l, m, k);
        return first_ge(2 * p + 1, m + 1, r, k);
    }

    int first_ge(ll k) const {
        return first_ge(1, 0, n - 1, k);
    }

    // consume k from first element >= k
    int consume_first_ge(vector<ll>& a, ll k) {
        int idx = first_ge(k);
        if (idx == -1) return -1;

        a[idx] -= k;
        update(1, 0, n - 1, idx, a[idx]);
        return idx;
    }
};
