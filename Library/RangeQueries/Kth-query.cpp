#include <bits/stdc++.h>
using namespace std;

struct SegTreeFreq {
    int n;
    vector<int> st;

    SegTreeFreq(int n): n(n), st(4 * n + 5, 0) {}

    void add(int p, int l, int r, int idx, int delta) {
        if (l == r) {
            st[p] += delta;
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m) add(2 * p, l, m, idx, delta);
        else add(2 * p + 1, m + 1, r, idx, delta);

        st[p] = st[2 * p] + st[2 * p + 1];
    }

    void add(int idx, int delta) {
        add(1, 0, n - 1, idx, delta);
    }

    // returns index of k-th element (1-indexed k), or -1 if k is invalid
    int kth(int p, int l, int r, int k) const {
        if (k <= 0 || k > st[p]) return -1;
        if (l == r) return l;

        int m = (l + r) / 2;
        if (st[2 * p] >= k) return kth(2 * p, l, m, k);
        return kth(2 * p + 1, m + 1, r, k - st[2 * p]);
    }

    int kth(int k) const {
        return kth(1, 0, n - 1, k);
    }
};
