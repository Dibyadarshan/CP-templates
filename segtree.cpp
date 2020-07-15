// https://judge.yosupo.jp/problem/point_add_range_sum
// Source: https://csacademy.com/lesson/segment_trees/

#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << "\n"
using namespace std;
using ll = long long;

template <typename T>
class Segtree {
public:
    int n;
    T inf;
    vector<T> segm_tree, a;

    Segtree(int n, T inf) {
        this->n = n;
        this->inf = inf;
        segm_tree.resize(4 * n + 5, inf);
        a.resize(n + 5, inf);
    }

    T combine(T x, T y) {
        return x + y;
    }

    void recalculate(int node) {
        //calculate the solution for the current segment,
        //considering the sons are correctly solved
        segm_tree[node] = combine(segm_tree[2 * node + 1], segm_tree[2 * node + 2]);
    }

    // build(0, 1, N);
    void build(int node, int left, int right) { //"node" is the index in the array, while "left"
                                            // and "right" are the ends of the current segment
        if (left == right) {
            segm_tree[node] = a[left]; //we are in a leaf node
        } else {
            int middle = (left + right) / 2;
            build(2 * node + 1, left, middle);
            build(2 * node + 2, middle + 1, right);
            recalculate(node);
        }
    }

    // update(0, 1, N, x, y);
    void update(int node, int left, int right, int x, T y) {
        if (left == right) { //we are in the xth leaf
            segm_tree[node] = y;
        } else {
            int middle = (left + right) / 2;
            if (x <= middle) { //we need to update the left son
                update(2 * node + 1, left, middle, x, y);
            } else {
                update(2 * node + 2, middle + 1, right, x, y);
            }
            //after updating said son, recalculate the current segment
            recalculate(node);
        }
    }

    T query(int node, int left, int right, int x, int y) {
        if (x <= left && right <= y) {
            //the segment of "node" is completely included in the query
            return segm_tree[node];
        } else {
            T answer = inf;
            int middle = (left + right) / 2;
            if (x <= middle) {
                //the query segment and the left son segment have at least one element in common
                answer = combine(answer, query(2 * node + 1, left, middle, x, y));
            }
            if (y >= middle + 1) {
                //the query segment and the right son segment have at least one element in common
                answer = combine(answer, query(2 * node + 2, middle + 1, right, x, y));
            }
            //we would not have entered this function if (x, y) and (left, right) had nothing in common,
            //so there is no risk of answer returning -Infinity here, as either the left or the right son
            //would update it
            return answer;
        }
    }

};

signed main() {
    IO;
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    int n, q; cin >> n >> q;
    Segtree<ll> s(n, 0);
    for(int i = 1; i <= n; ++i) cin >> s.a[i];
    s.build(0, 1, n);
    while(q--) {
        int choice, x, y; cin >> choice >> x >> y;
        if(choice == 0) {
            s.update(0, 1, n, x + 1, y + s.a[x + 1]);
            s.a[x + 1] += y;
        }
        else {
            cout << s.query(0, 1, n, x + 1, y) << "\n";
        }
    }
    return 0;
}