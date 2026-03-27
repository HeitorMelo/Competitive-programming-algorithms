/*
Colecao de Nodes para Segment Tree / Sparse Table
Copie o Node que voce precisa para o seu codigo.
Requisitos: Cada Node deve ter static merge() e construtor identidade.
Para Lazy: Node deve ter apply(TAG, l, r).

Créditos: Modificado de lua (Lua Guimarães)
Fonte: github.com/src-lua/lgf-cpLib
*/

// NODES BASICOS (Idempotentes - para Sparse Table tambem)

#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct SumNode {
    ll val = 0;
    SumNode(ll v = 0) : val(v) {}

    static inline SumNode merge(const SumNode& l, const SumNode& r) {
        return SumNode(l.val + r.val);
    }

    // Para Lazy com AddTag
    void apply(ll add, int len) {
        val += add * len;
    }
};

struct MinNode {
    ll val = LLONG_MAX;
    int pos = -1;
    MinNode(ll v = LLONG_MAX, int p = -1) : val(v), pos(p) {}

    static inline MinNode merge(const MinNode& l, const MinNode& r) {
        return l.val <= r.val ? l : r;
    }
};


// NODES AVANCADOS

// --- Matrix 2x2 Node (para Fibonacci, recorrências lineares) ---
// Exemplo: fib(n) = [[1,1],[1,0]]^n * [[1],[0]]
const ll MOD = 1e9 + 7;

struct Matrix2x2Node {
    ll a[2][2];

    Matrix2x2Node() {
        memset(a, 0, sizeof a);
        a[0][0] = a[1][1] = 1; // identidade
    }

    Matrix2x2Node(ll a00, ll a01, ll a10, ll a11) {
        a[0][0] = a00; a[0][1] = a01;
        a[1][0] = a10; a[1][1] = a11;
    }

    static inline Matrix2x2Node merge(const Matrix2x2Node& l,
                                       const Matrix2x2Node& r) {
        Matrix2x2Node res;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++) {
                res.a[i][j] = 0;
                for(int k = 0; k < 2; k++)
                    res.a[i][j] = (res.a[i][j] + l.a[i][k] * r.a[k][j]) % MOD;
            }
        return res;
    }
};

// --- Range Sum com contador ---
// Util para queries tipo: "quantos elementos < x no range [l,r]"
struct CountNode {
    ll sum = 0;
    int cnt = 0;
    CountNode(ll s = 0, int c = 0) : sum(s), cnt(c) {}

    static inline CountNode merge(const CountNode& l, const CountNode& r) {
        return CountNode(l.sum + r.sum, l.cnt + r.cnt);
    }
};

// --- Max Subarray Sum Node ---
// Mantem soma total, melhor prefixo, melhor sufixo e melhor subarray no range.
struct SubarraySumNode {
    ll sum = 0;
    ll pref = LLONG_MIN / 4;
    ll suff = LLONG_MIN / 4;
    ll best = LLONG_MIN / 4;

    // Identidade para query fora do range.
    SubarraySumNode() = default;

    // Folha com valor unico.
    SubarraySumNode(ll v) : sum(v), pref(v), suff(v), best(v) {}

    static inline SubarraySumNode merge(const SubarraySumNode& l,
                                        const SubarraySumNode& r) {
        SubarraySumNode ans;
        ans.sum = l.sum + r.sum;
        ans.pref = max(l.pref, l.sum + r.pref);
        ans.suff = max(r.suff, r.sum + l.suff);
        ans.best = max({l.best, r.best, l.suff + r.pref});
        return ans;
    }
};

// --- Função Linear Node (composição de funções: f(x) = ax + b) ---
// Muito útil para composição de funções em árvores
struct LinearFunctionNode {
    ll a = 1, b = 0; // f(x) = ax + b

    LinearFunctionNode(ll _a = 1, ll _b = 0) : a(_a % MOD), b(_b % MOD) {}

    // Composicao: (f o g)(x) = f(g(x)) = f(gx + h) = a(gx + h) + b
    // = (ag)x + (ah + b)
    static inline LinearFunctionNode merge(const LinearFunctionNode& f,
                                            const LinearFunctionNode& g) {
        return LinearFunctionNode(
            (f.a * g.a) % MOD,
            (f.a * g.b + f.b) % MOD
        );
    }

    // Aplica a função: f(x) = ax + b
    ll eval(ll x) const {
        return (a * x + b) % MOD;
    }
};

// EXEMPLOS DE USO

/*
// --- Segment Tree com SumNode ---
SegTree<SumNode> st(n);
st.update(i, SumNode(val));
SumNode result = st.query(l, r);
cout << result.val << '\n';

// --- Sparse Table com MinNode (RMQ) ---
SparseTable<MinNode> sp(v);
MinNode minimo = sp.query(l, r);
cout << "Min: " << minimo.val << " at position " << minimo.pos << '\n';

// --- Matrix para Fibonacci ---
SegTree<Matrix2x2Node> st(n);
Matrix2x2Node fib(1, 1, 1, 0);
st.update(i, fib);

// --- Composição de Funções Lineares ---
SegTree<LinearFunctionNode> st(n);
st.update(i, LinearFunctionNode(2, 3)); // f(x) = 2x + 3
st.update(j, LinearFunctionNode(4, 1)); // g(x) = 4x + 1
// merge(f, g) = f(g(x)) = 2(4x + 1) + 3 = 8x + 5
LinearFunctionNode composed = st.query(l, r);
ll result = composed.eval(x);
*/