#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define rep(i,n) for (int i = 0; i < n; i++) //LATEX_IGNORED_LINE
const int MOD = 1e9 + 7; //LATEX_IGNORED_LINE

ll gcd_ll(ll a, ll b) {
    while (b != 0) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

ll lcm_ll(ll a, ll b) {
    return a / gcd_ll(a, b) * b;
}

// Bit manipulation utilities
ll count_set_bits(ll n) {
    return __popcount<ll>(n); // __builtin_popcount(n);
}

inline ll safe_mod(ll x) {
    return (x % MOD + MOD) % MOD;
}