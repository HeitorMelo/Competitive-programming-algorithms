#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE

struct Node {
    ll sum, pref, suff, best;
};

struct SegTreeMaxSubarray {
    int n;
    vector<Node> st;

    SegTreeMaxSubarray(const vector<ll>& a) {
        n = (int)a.size();
        st.assign(4 * n + 5, {0, 0, 0, 0});
        build(1, 0, n - 1, a);
    }

    Node merge_node(const Node& L, const Node& R) const {
        Node ans;
        ans.sum = L.sum + R.sum;
        ans.pref = max(L.pref, L.sum + R.pref);
        ans.suff = max(R.suff, R.sum + L.suff);
        ans.best = max({L.best, R.best, L.suff + R.pref});
        return ans;
    }

    void build(int p, int l, int r, const vector<ll>& a) {
        if (l == r) {
            st[p] = {a[l], a[l], a[l], a[l]};
            return;
        }

        int m = (l + r) / 2;
        build(2 * p, l, m, a);
        build(2 * p + 1, m + 1, r, a);
        st[p] = merge_node(st[2 * p], st[2 * p + 1]);
    }

    void update(int p, int l, int r, int idx, ll val) {
        if (l == r) {
            st[p] = {val, val, val, val};
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m) update(2 * p, l, m, idx, val);
        else update(2 * p + 1, m + 1, r, idx, val);

        st[p] = merge_node(st[2 * p], st[2 * p + 1]);
    }

    void update(int idx, ll val) {
        update(1, 0, n - 1, idx, val);
    }

    ll max_subarray_sum() const {
        return st[1].best;
    }
};
