#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,a,n) for(long long i=a;i<=n;++i)
#define dbg1(a,b,c) cout<<"\n->"<<a<<" "<<b<<" "<<c<<"\n"; 
#define dbg2(a,b,c) cout<<"\n--"<<a<<" "<<b<<" "<<c<<"\n"; 
using namespace std;

typedef long long ll;
typedef long double ld;

ll mod=(ll)1e9+7;
ll Mul(ll a, ll b, ll M){
    ll res = 0;
    const int k = 14;// floor(64 - log2(MAX_VALUE))
    while (a > 0) {
        int intA = a & ((1 << k) - 1);
        res = (res + b * intA) % M;
        a >>= k;
        b = (b << k) % M;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    
	return 0;
}