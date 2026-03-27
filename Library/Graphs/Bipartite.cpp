#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define INF 1000000000 //LATEX_IGNORED_LINE

bool bipartite(int n, vector<vector<int>>& g) {
    vector<int> color(n + 1, -1);
    bool ok = true;

    for (int i = 1; i <= n && ok; i++) {
        if (color[i] != -1) continue;
        queue<int> q;
        q.push(i);
        color[i] = 0;

        while (!q.empty() && ok) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    ok = false;
                    break;
                }
            }
        }
    }

    return ok;
}