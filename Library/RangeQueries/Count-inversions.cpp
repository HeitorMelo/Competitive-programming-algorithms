#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE

ll merge_count(vector<int>& a, int l, int r) {
    if (l >= r) return 0;

    int mid = (l + r) / 2;
    ll inv = merge_count(a, l, mid) + merge_count(a, mid + 1, r);

    vector<int> temp;
    temp.reserve(r - l + 1);

    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else {
            inv += (mid - i + 1);
            temp.push_back(a[j++]);
        }
    }

    while (i <= mid) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = 0; k < (int)temp.size(); k++) {
        a[l + k] = temp[k];
    }

    return inv;
}

ll count_inversions(vector<int> a) {
    if (a.empty()) return 0;
    return merge_count(a, 0, (int)a.size() - 1);
}
