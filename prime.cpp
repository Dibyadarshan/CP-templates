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
ll p[(ll)1e5];
ll sieve(){
	for(ll i=2;i*i<=1e5;++i){
		if(!p[i]){
			for(ll j=i*i;j<=1e5;j=j+i) p[j]=1;
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    memset(p,0,sizeof(p));
   	sieve();
    
	return 0;
}