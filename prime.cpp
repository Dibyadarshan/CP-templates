// https://codeforces.com/problemset/problem/222/C
#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << "\n"
using namespace std;
using ll = long long;

const ll lim = 10000000;
vector<ll> divisor(lim + 5);
vector<bool> isprime(lim + 5, true);

void sieve() {
	for(ll i = 1; i <= lim; ++i) divisor[i] = i;
	
	isprime[1] = false;
	
	for(ll i = 2; i * i <= lim; ++i) {
		if(isprime[i]) {
			for(ll j = i * i; j <= lim; j += i) {
				if(isprime[j]) {
					isprime[j] = false;
					divisor[j] = i; 
				}
			}
		}
	}

}

signed main() {
    IO;
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    sieve();
    int r1, n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<int> c1(lim + 5, 0), c2(lim + 5, 0), d1(lim + 5, 0), d2(lim + 5, 0);
    for(int i = 0; i < n; ++i) {
    	cin >> a[i]; r1 = a[i];
    	while(divisor[r1] != r1) {
    		++c1[divisor[r1]]; r1 /= divisor[r1];
    	}
    	if(r1 != 1) ++c1[divisor[r1]];
    }
    for(int i = 0; i < m; ++i) {
    	cin >> b[i]; r1 = b[i];
    	while(divisor[r1] != r1) {
    		++c2[divisor[r1]]; r1 /= divisor[r1];
    	}
    	if(r1 != 1) ++c2[divisor[r1]];
    }
    for(int i = 0; i < n; ++i) {
    	r1 = a[i];
    	while(divisor[r1] != r1) {
    		if(min(c1[divisor[r1]], c2[divisor[r1]]) > 0) {
    			if(d1[divisor[r1]] < min(c1[divisor[r1]], c2[divisor[r1]])) {
    				++d1[divisor[r1]];
    				a[i] /= divisor[r1];
    			}
    		} 
    		r1 /= divisor[r1];
    	}
    	if(r1 != 1) {
    		if(min(c1[divisor[r1]], c2[divisor[r1]]) > 0) {
    			if(d1[divisor[r1]] < min(c1[divisor[r1]], c2[divisor[r1]])) {
    				++d1[divisor[r1]];
    				a[i] /= divisor[r1];
    			}
    		}
    	}
    }
    for(int i = 0; i < m; ++i) {
    	r1 = b[i];
    	while(divisor[r1] != r1) {
    		if(min(c1[divisor[r1]], c2[divisor[r1]]) > 0) {
    			if(d2[divisor[r1]] < min(c1[divisor[r1]], c2[divisor[r1]])) {
    				++d2[divisor[r1]];
    				b[i] /= divisor[r1];
    			}
    		} 
    		r1 /= divisor[r1];
    	}
    	if(r1 != 1) {
    		if(min(c1[divisor[r1]], c2[divisor[r1]]) > 0) {
    			if(d2[divisor[r1]] < min(c1[divisor[r1]], c2[divisor[r1]])) {
    				++d2[divisor[r1]];
    				b[i] /= divisor[r1];
    			}
    		}
    	}
    }

    cout << n << " " << m << "\n";
    for(int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << "\n";
	for(int i = 0; i < m; ++i) cout << b[i] << " ";
    return 0;
}