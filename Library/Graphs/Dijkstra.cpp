#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
const int MAXN = 1e6 + 5; //LATEX_IGNORED_LINE
#define INF 1000000000 //LATEX_IGNORED_LINE

vector<pii> g[MAXN];

void dijkstra(int s, int n, vector<ll>& d) {
    d.assign(n, INF);

    priority_queue<pii, vector<pii>, greater<pii>> q;
    d[s] = 0; q.push({0, s});

    while (!q.empty()) {
        auto [d_u, u] = q.top(); q.pop();
        if (d_u > d[u]) continue;

        for (auto [v, w] : g[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}