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

void update(ll idx, ll val){
    while(idx<=n){
        bit[idx]+=val;
        idx+=(idx & (-idx));
    }
}

ll query(ll idx){
    ll ans=0;
    while(idx>0){
        ans+=bit[idx];
        idx-=(idx & (-idx));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    
	return 0;
}
