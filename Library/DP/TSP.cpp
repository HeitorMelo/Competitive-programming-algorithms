#include <algorithm>

const int MAX_N = 20; // Maximum number of nodes/cities
const int INF = 2000000000; // 2e9, a large value for infinity

int n, m; // 'n' will store the actual number of nodes used
int g[MAX_N][MAX_N]; // Cost/distance matrix
int dp[MAX_N][1 << MAX_N]; // DP table: 20 rows, 2^20 columns

// 1. Set the actual number of nodes 'n' (n <= MAX_N).
// 2. Populate the cost matrix 'g[i][j]' with distances/costs.
// 3. Initialize 'dp[i][mask]' with a sentinel value like -1.
// 4. Call the function as 'solve(0, 1)' (Start at node 0 with only node 0 visited).

int solve(int i, int mask) {
    if (mask == ((1 << n) - 1)) {
        return g[i][0];
    }
    
    if (dp[i][mask] != -1) { 
        return dp[i][mask];
    }
    
    int ans = INF;

    for (int j = 0; j < n; j++) {
        if (mask & (1 << j)) continue; 

        ans = std::min(ans, g[i][j] + solve(j, mask ^ (1 << j))); 
    }

    return dp[i][mask] = ans;
}
