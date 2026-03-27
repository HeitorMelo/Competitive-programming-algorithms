#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define rep(i,n) for (int i = 0; i < n; i++) //LATEX_IGNORED_LINE

/*LATEX_DESC_BEGIN************************
DP Top-Down (Memoization)
***************************LATEX_DESC_END*/

const ll INF = 1e18; 

const int MAX_STATE_1 = 1005;
const int MAX_STATE_2 = 1005;

const int BASE_VALUE = 0; 

ll memo[MAX_STATE_1][MAX_STATE_2];

ll solve(int state1, int state2 /*, const vector<int>& arr */) {
    // 2. Base case: Invalid states (Out of bounds, insufficient capacity, etc.)
    // Return INF for minimization problems, -INF for maximization problems
    if (state1 < 0 || state2 < 0 /*...*/) return INF; 

    // 3. Base case: Target state reached
    if (state1 == 0 && state2 == 0 /*...*/) return BASE_VALUE;

    // 4. Memoization check using reference
    ll &ans = memo[state1][state2 /*...*/];
    
    // Check against the 'uncomputed' flag (-1), NOT the 'invalid path' value
    if (ans != -1) return ans;

    // 5. Recursive case - try all possible transitions
    ans = INF; // Initialize to worst possible outcome (INF for min, -INF for max)
    
    // for (all possible transitions) {
    //     ll cost_of_transition = ...;
    //     ans = f(ans, solve(new_state1, new_state2) + cost_of_transition);
    // }
    //  f is a function that combines the results (e.g., min or max)

    return ans;
}


// memset(memo, -1, sizeof(memo));