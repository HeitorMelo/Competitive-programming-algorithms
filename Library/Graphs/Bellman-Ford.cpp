#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define INF 1000000000 //LATEX_IGNORED_LINE

vector<tiii> edges;

void bellman_ford(int s, int n, vector<ll>& dist) {
    dist.assign(n, INF);
    dist[s] = 0;
    vector<int> p(n, -1);

    int x = -1; // cycle detect
    for (int i = 0; i < n; i++) {
        x = -1;
        for (int j = 0; j < edges.size(); j++) {
            auto [u, v, w] = edges[j];
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                x = v; p[v] = u;
            }
        }
    }

    if (x == -1) {} // no cycle
    else {
        int y = x;
        for (int i = 0; i < n; i++)
            y = p[y];

        vector<int> cycle;
        for (int cur = y;; cur = p[cur]) {
            cycle.push_back(cur);
            if (cur == y && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end()); // negative cycle
    }
}