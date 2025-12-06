#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define INF 1000000000 //LATEX_IGNORED_LINE
#define rep(i,n) for (int i = 0; i < n; i++) //LATEX_IGNORED_LINE

vector<int> w, v;
// W = knaps capacity, n = n items
// w[i] = weight, v[i] = value
int knapsack(int n, int W) {
    vector<int> dp(W + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int k = W - w[i]; k >= 0; k--) {
            dp[k + w[i]] = max(dp[k + w[i]], dp[k] + v[i]);
        }
    }
    
    return dp[W];
}