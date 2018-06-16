// http://codeforces.com/contest/339/problem/D
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
ll t[1000000],a[1000000];
ll up,pos;
void build(ll val, ll begin, ll end, ll dep){
    if(begin==end){
        t[val]=a[begin];
        return;
    }
    ll mid=(begin+end)/2;
    build(val*2,begin,mid,dep-1);
    build(val*2+1,mid+1,end,dep-1);
    if(dep&1) t[val]=t[val*2] ^ t[val*2+1];
    else t[val]=t[val*2] | t[val*2+1];
    // dbg1(val,t[val],dep);
}
void update(ll val, ll begin, ll end, ll dep){
    if(begin==end){
        t[val]=up;
        return;
    }
    ll mid=(begin+end)/2;
    if(pos<=mid) update(2*val,begin,mid,dep-1);
    else update(2*val+1,mid+1,end,dep-1);
    if(dep&1) t[val]=t[val*2] ^ t[val*2+1];
    else t[val]=t[val*2] | t[val*2+1];
    // dbg2(val,t[val],dep);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n,m;
    ll r1,r2,dep;
    cin>>n>>m;
    dep=n+1;
    n=pow(2,n);
    rep(i,0,n-1) cin>>a[i];
    build(1,0,n-1,dep);
    rep(i,1,m){
        cin>>pos>>up;
        --pos;
        update(1,0,n-1,dep);
        cout<<t[1]<<"\n";
    }
    return 0;
}
