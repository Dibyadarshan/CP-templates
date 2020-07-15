// https://codeforces.com/contest/13/problem/E
#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << "\n"
using namespace std;
using ll = long long;

signed main() {
    IO;
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    int n, m; cin >> n >> m;
    vector<int> pw(n), jump(n, 0), last(n, 0);
    for(int i = 0; i < n; ++i) cin >> pw[i];

    int sq = ceil(sqrtl((long double)n));

    for(int i = n - 1; i >= 0; --i) {
        if(i + pw[i] >= n) {
            last[i] = i; jump[i] = 1;
        }
        else if((i + pw[i]) / sq == i / sq) {
            last[i] = last[i + pw[i]]; jump[i] = 1 + jump[i + pw[i]];
        }
        else {
            last[i] = i; jump[i] = 1;   
        }
    }

    while(m--) {
        int choice, a, b; cin >> choice;
        if(choice == 0) {
            cin >> a >> b;
            --a;
            pw[a] = b;
            int start = min(n - 1, (a / sq + 1) * sq - 1);
            for(int i = start; i >= (a / sq) * sq; --i) {
                if(i + pw[i] >= n) {
                    last[i] = i; jump[i] = 1;
                }
                else if((i + pw[i]) / sq == i / sq) {
                    last[i] = last[i + pw[i]]; jump[i] = 1 + jump[i + pw[i]];
                }
                else {
                    last[i] = i; jump[i] = 1;   
                }
            }
        }
        else {
            cin >> a;
            --a;
            int mv = 0, ls = a;
            while(ls + pw[ls] < n) {
                mv += jump[ls];
                int x = last[ls] + pw[last[ls]];
                if(x >= n) {
                    --mv;
                    ls = last[ls];
                    break;
                }
                ls = x;
            }
            cout << ls + 1 << " " << mv + 1 << "\n"; 
        }
    }
    return 0;
}