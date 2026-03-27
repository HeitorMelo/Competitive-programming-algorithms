#include <bits/stdc++.h>
using namespace std;

template <typename F>
long long binary_search_answer(long long l, long long r, F ok) {

    while (l < r) {
        long long mid = l + (r - l) / 2;

        if (ok(mid))
            r = mid;
        else
            l = mid + 1; // change 
    }

    return l;
}