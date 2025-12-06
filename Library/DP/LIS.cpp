#include <bits/stdc++.h>
using namespace std;

#define ll long long int //LATEX_IGNORED_LINE
#define tiii tuple<int,int,int> //LATEX_IGNORED_LINE
#define pii pair<ll,ll> //LATEX_IGNORED_LINE
#define INF 1000000000 //LATEX_IGNORED_LINE
#define rep(i,n) for (int i = 0; i < n; i++) //LATEX_IGNORED_LINE

int lis(vector<int>& nums) {
    vector<int> v;

    for (auto x: nums) {
        auto it = lower_bound(v.begin(), v.end(), x);
        // lower -> a > b 
        // upper -> a >= b (allow duplicates)
        
        if (it == v.end()) v.push_back(x);
        else *it = x;
    }

    return v.size();
}