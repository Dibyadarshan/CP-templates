// https://www.spoj.com/problems/LCPCP2/
#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << "\n"
using namespace std;
using ll = long long;

// const ll mod;
ll mod;

ll expo(ll a, ll b) {
	if(a == 0 && b > 0) return 0;
	a = a % mod;
	ll ret = 1;
	while(b > 0) {
		if(b & 1) ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}

signed main() {
    IO;
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int tests = 1;
    cin >> tests;
    for(int test = 1; test <= tests; ++test) {
        ll a, b, c; cin >> a >> b >> c;
        mod = c;
        cout << test << ". " << expo(a, b) << "\n"; 
    }
    return 0;
}