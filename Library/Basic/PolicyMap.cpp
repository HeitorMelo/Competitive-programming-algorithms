#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T1, typename T2> 
using ordered_map = tree<T1, T2, less<T1>, rb_tree_tag, tree_order_statistics_node_update>;

class MapPolicy {
private:
    ordered_map<int, int> pbds;

public:
    MapPolicy() {
        pbds.clear();
    }

    void add(int key, int value) {
        pbds[key] = value;
    }
    void remov(int key) {
        auto it = pbds.find(key);
        if (it != pbds.end()) {
            pbds.erase(it);
        }
    }
    int get(int key) {
        if (pbds.find(key) != pbds.end()) return pbds[key];
        return -1; // Some default value
    }
    pair<int, int> kth(int k) {
        auto it = pbds.find_by_order(k);
        if (it == pbds.end()) return {-1, -1}; //
        return {it->first, it->second};
    }

    int countLess(int key) {
        return pbds.order_of_key(key);
    }
    int countEqual(int key) {
        return (pbds.find(key) != pbds.end()) ? 1 : 0;
    }
    int countLessOrEqual(int key) {
        if (pbds.find(key) != pbds.end()) return pbds.order_of_key(key) + 1;
        return pbds.order_of_key(key);
    }
    int countGreater(int key) {
        return pbds.size() - countLessOrEqual(key);
    }
};