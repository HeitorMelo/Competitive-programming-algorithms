#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define INF 1000000000 //LATEX_IGNORED_LINE
#define rep(i,n) for (int i = 0; i < n; i++) //LATEX_IGNORED_LINE

struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n+1), size(n+1) {
        for(int i=0; i<=n; i++) {parent[i] = i; size[i] = 1;}
    }

    int find(int u) {
        if (parent[u] == u) return u;
        
        return parent[u] = find(parent[u]);
    }

    void join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;

        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
};