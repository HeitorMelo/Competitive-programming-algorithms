/*LATEX_DESC_BEGIN***************************
    Combinação modular
    Inverso modular
    Exponenciação rápida (O (Log P ) - p: potência)
    O(N) fatorial
*****************************LATEX_DESC_END*/

#include <iostream>
#include <vector>
#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define rep(i,n) for (int i = 0; i < n; i++) //LATEX_IGNORED_LINE
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5;

ll fact[MAX];
ll invFact[MAX];

// Binary exponentiation for modular inverse
ll modPow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Fermat's Little Theorem for modular inverse
ll modInverse(ll n) {
    return modPow(n, MOD - 2);
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX - 1] = modInverse(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// O(1) combinations: nCr % MOD
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    ll num = fact[n];
    ll den = (invFact[r] * invFact[n - r]) % MOD;
    return (num * den) % MOD;
}