#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define INF 1000000000 //LATEX_IGNORED_LINE
#define rep(i,n) for (int i = 0; i < n; i++) //LATEX_IGNORED_LINE

int lcs(string a, string b) {
    vector<vector<int>> m(a.size()+1, vector<int>(b.size()+1));
    for (int i = a.size(); i >= 0; i--) {
        for (int j = b.size(); j >= 0; j--) {
            if (i == a.size() || j == b.size()) {
                m[i][j] = 0; continue;
            }

            if (a[i] == b[j]) m[i][j] = 1 + m[i+1][j+1];
            else m[i][j] = max(m[i][j+1], m[i+1][j]);
        }
    }

    return m[0][0]; // result
}