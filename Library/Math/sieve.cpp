#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
int divi[MAX];
int mobius[MAX];
vector<int> primes;

// Builds the SPF table (smallest prime factor) and prime list for [1..lim].
// Precondition: lim < MAX.
void crivo(int lim) {
    if (lim <= 0) return;
    lim = min(lim, MAX - 1);
    fill(divi, divi + MAX, 0);
    primes.clear();
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
            if (j > divi[i] || 1LL * i * j > lim) break;
            divi[i * j] = j;
		}
	}
}

// Builds SPF and Mobius values mu(n) for [1..lim] in linear time.
// Precondition: lim < MAX.
void crivo_mobius(int lim) {
    if (lim <= 0) return;
    lim = min(lim, MAX - 1);
    fill(divi, divi + MAX, 0);
    fill(mobius, mobius + MAX, 0);
    primes.clear();
    mobius[1] = 1;
    for (int i = 2; i <= lim; i++) {
        if (!divi[i]) {
            divi[i] = i;
            primes.push_back(i);
            mobius[i] = -1; 
        }
        for (int p : primes) {
            if (p > divi[i] || 1LL * i * p > lim) break;
            divi[i*p] = p;
            if (i % p == 0) {
                mobius[i*p] = 0; 
                break;
            } else {
                mobius[i*p] = -mobius[i];
            }
        }
    }
}

// Factorizes n using the SPF table and appends prime factors in sorted order.
// Requires crivo/crivo_mobius to be called first with lim >= n.
void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}

/*LATEX_DESC_BEGIN***************************
    Sieve linear - Encontra o menor divisor primo
   Fact -> Fatora um número <= limite, sai ordenada
   Crivo calcula a lista de primos
   
   Crivo_mobius
		- 1 se n=1
		- 0 se n tem algum fator primo ao quadrado
		- (-1)^k se n é produto de k primos distintos

   A função fact adiciona o número 1 se vc tentar fatorar o 1.
   Complexidade:
   crivo - O(n log(logN))
   fact - O(log(n))
*****************************LATEX_DESC_END*/