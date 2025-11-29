#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define INF 1000000000 //LATEX_IGNORED_LINE
#define rep(i,n) for (int i = 0; i < n; i++) //LATEX_IGNORED_LINE

bool floyd_warshall(int n, vector<vector<pii>>& g) {
    vector<vector<ll>> d(n);
    d.assign(n, vector<ll>(n, INF));
    rep(i, n) d[i][i] = 0;
    rep(i, n) for (auto [j,w]: g[i]) d[i][j] = w;

    rep(k, n)
    rep(i, n)
    rep(j, n)
        if (d[i][k] < INF && d[k][j] < INF)
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    rep(i, n)
        if (d[i][i] < 0) return true; // cycle
    
    return false;
}