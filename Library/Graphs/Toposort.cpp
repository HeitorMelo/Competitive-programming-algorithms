#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define rep(i,n) for (int i = 0; i < n; i++) //LATEX_IGNORED_LINE

/*LATEX_DESC_BEGIN************************
Topological Sort (Kahn's Algorithm)
 - O(V + E)
 - Requisitos: DAG
***************************LATEX_DESC_END*/

bool toposort(int n, vector<vector<int>>& g, vector<int>& inDegree) {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            if (--inDegree[v] == 0) q.push(v);
        }
    }

    if ((int)order.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << order[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
    
}