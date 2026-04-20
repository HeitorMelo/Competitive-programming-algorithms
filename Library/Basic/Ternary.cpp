#include <bits/stdc++.h>
using namespace std;

// Ternary search on a unimodal function in [l, r].
double ternary_search_max(double l, double r, function<double(double)> f) {
    // 200 iterations cover 1e-6 precision even in [0,1e9]
    for (int it = 0; it < 200; ++it) {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;

        if (f(m1) < f(m2)) l = m1; // change to > for minimum
        else r = m2;
    }
    return f((l + r) / 2.0);
}

/*LATEX_DESC_BEGIN***************************
    Ternary Search - Busca ternária em função unimodal (máximo ou mínimo)
    Complexidade: O(log(n)) - n: intervalo de busca
*****************************LATEX_DESC_END*/