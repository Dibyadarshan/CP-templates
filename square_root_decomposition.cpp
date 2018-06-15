// http://codeforces.com/contest/220/problem/B
// Offline: Mo's algorithm
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
ll n,m,a[100005];
ll sq;

bool comp(pair<pair<ll,ll>,ll> x, pair<pair<ll,ll>,ll> y){
	if((x.first.first)/sq==(y.first.first)/sq){
		return x.first.second<y.first.second;
	}
	return (x.first.first)/sq<(y.first.first)/sq;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    
    cin>>n>>m;
    rep(i,0,n-1){cin>>a[i];if(a[i]>100000)a[i]=100001;}
    sq=sqrt(n);
    ll r1,r2;
    pair<pair<ll,ll>,ll> query[m];
    rep(i,0,m-1){
    	cin>>r1>>r2;
    	--r1,--r2;
    	query[i]=mp(mp(r1,r2),i);
    }
    sort(query,query+m,comp);
	ll ans[100005];
	ll result=0,begin=query[0].first.first,end=query[0].first.second,cnt[100005];
	memset(cnt,0,sizeof(cnt));
	rep(i,begin,end){
		++cnt[a[i]];
		if(cnt[a[i]]==a[i]+1){
			--result;
		}
		else if(cnt[a[i]]==a[i]){
			++result;
		}
	}
	ans[query[0].second]=result;
	rep(i,1,m-1){	
		r1=query[i].first.first;
		r2=query[i].first.second;
		// First
		if(r1<begin){
			while(r1<begin){
				++cnt[a[r1]];
				if(cnt[a[r1]]==a[r1]) ++result;
				else if(cnt[a[r1]]==a[r1]+1) --result;
				++r1;
			}
		}
		else if(r1>begin){
			--r1;
			while(r1>=begin){
				--cnt[a[r1]];
				if(cnt[a[r1]]==a[r1]) ++result;
				else if(cnt[a[r1]]==a[r1]-1) --result;
				--r1;
			}
		}
		// Second

		if(r2>end){
			while(r2>end){
				++cnt[a[r2]];
				if(cnt[a[r2]]==a[r2]) ++result;
				else if(cnt[a[r2]]==a[r2]+1) --result;
				--r2;
			}
		}
		else if(r2<end){
			++r2;
			while(r2<=end){
				--cnt[a[r2]];
				if(cnt[a[r2]]==a[r2]) ++result;
				else if(cnt[a[r2]]==a[r2]-1) --result;
				++r2;
			}
		}
		// dbg1(result,r1,r2);
		// dbg2(begin,end,0);
		ans[query[i].second]=result;
		begin=query[i].first.first;
		end=query[i].first.second;	
	}	
	// cout<<"\n";
	rep(i,0,m-1) cout<<ans[i]<<"\n";
	return 0;
}

// Other square root decomposition problems
