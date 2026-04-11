#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define INF 1000000000 //LATEX_IGNORED_LINE
#define rep(i,n) for (int i = 0; i < n; i++) //LATEX_IGNORED_LINE

vector<int> w, v;
vector<vector<int>> memo;

// max sum(v) with sum(w) <= remW
int subsum(int id, int remW) {
    if ((id == w.size()) || (remW == 0)) return 0;

    int &ans = memo[id][remW];
    if (ans != -1) return ans;

    if (w[id] > remW) return ans = subsum(id+1, remW);

    return ans = max(subsum(id + 1, remW), 
                     v[id]+subsum(id+1, remW-w[id]));
}

// which values can be created from a list a (int)
int subsumi(int n, int max_v, vector<int> a) {
    vector<int> m(max_v + 10, 0);

    m[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = max_v; j >= a[i]; j--) {
            m[j] |= m[j - a[i]];
        }
    }

    return m[max_v];
}