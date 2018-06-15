// http://codeforces.com/contest/13/problem/E
// Online
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define dbg1(a,b,c) cout<<"\n->"<<a<<" "<<b<<" "<<c<<"\n"; 
#define dbg2(a,b,c) cout<<"\n--"<<a<<" "<<b<<" "<<c<<"\n"; 
using namespace std;

typedef long long ll;
typedef long double ld;

// int mod=(int)1e9+7;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NUint);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    
    int nn,m,a[100005],n[100005],h[100005],cur[100005];
    // cin>>nn>>m;
    scanf("%d %d",&nn,&m);
    int sq=sqrt(nn),size=sq+1;
    if(sq*sq==nn) --size;
    rep(i,0,nn-1) scanf("%d",&a[i]);
    int a1,a2,r1,r2;
    // n[100001]=0;
    memset(n,0,sizeof(n));
    for(a1=nn-1;a1>-1;--a1){
    	if(a[a1]+a1>nn-1){
    		n[a1]=1,h[a1]=100001;
    		cur[a1]=a1;
    		// dbg1(a1,n[a1],h[a1]);
    		continue;
    	}
    	r1=a1/sq;
    	r1=r1*sq+sq;
    	if(a[a1]+a1>=r1){
    		n[a1]=1;
    		h[a1]=a[a1]+a1;
    		cur[a1]=a1;
    		// dbg1(a1,n[a1],h[a1]);
    		// dbg1(r1,a1/sq,a[a1]+a1);
    		continue;
    	}
    	n[a1]=1+n[a1+a[a1]];
    	h[a1]=h[a1+a[a1]];
    	cur[a1]=cur[a1+a[a1]];
    	// dbg2(a1,n[a1],h[a1]);
    }
    // cout<<"\n\n";
    int type,one,two,ans;
    while(m--){
    	// cin>>type;
    	scanf("%d",&type);
    	if(type){
    		// cin>>one;
    		scanf("%d",&one);
    		--one,ans=0;
    		r1=one;int prev;
    		while(n[r1]){
    			// dbg1(r1,ans,h[r1]);
    			ans+=n[r1];
    			prev=cur[r1];
    			r1=h[r1];
    			
    		}
    		// dbg1(prev+1,ans,0);
    		printf("%d %d\n",prev+1,ans);
    		// cout<<prev+1<<" "<<ans<<"\n";
    	}
    	else{
    		// cin>>one>>two;
    		scanf("%d %d",&one,&two);
    		--one;
    		a[one]=two;
    		a2=one/sq;
    		a2=a2*sq;
    		for(a1=one;a1>=a2;--a1){
		    	if(a[a1]+a1>nn-1){
		    		n[a1]=1,h[a1]=100001;
		    		cur[a1]=a1;
		    		// dbg2(a1,h[a1],n[a1]);
		    		continue;
		    	}
		    	r1=a1/sq;
		    	r1=r1*sq;
		    	r1=r1+sq;
		    	if(a[a1]+a1>=r1){
		    		n[a1]=1;
		    		cur[a1]=a1;
		    		h[a1]=a[a1]+a1;
		    		// dbg2(a1,h[a1],n[a1]);	
		    		continue;
		    	}
		    	cur[a1]=cur[a1+a[a1]];
		    	n[a1]=1+n[a1+a[a1]];
		    	h[a1]=h[a1+a[a1]];
		    	// dbg2(a1,h[a1],n[a1]);
		    		
		    }
    	}
    }
	return 0;
}
