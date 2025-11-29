#include <bits/stdc++.h>
using namespace std;
#include "DSU.cpp" //LATEX_IGNORED_LINE

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define INF 1000000000 //LATEX_IGNORED_LINE
#define rep(i,n) for (int i = 0; i < n; i++) //LATEX_IGNORED_LINE

struct edge {int u, v, w;};
bool comp(edge a, edge b) {return a.w < b.w;};

vector<edge> edges;

int kruskal(int n) {
    DSU ds(n);
    sort(edges.begin(), edges.end(), comp);

    int cost;
    for (auto [u, v, w] : edges) {
        if (ds.find(u) != ds.find(v)) {
            cost += w;
            ds.join(u, v);
        }
    }

    return cost;
}