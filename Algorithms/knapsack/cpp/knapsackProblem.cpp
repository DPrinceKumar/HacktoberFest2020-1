// Dynamic programming knapsac problem
#pragma GCC optimize("unroll-loops,no-stack-protector,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <iostream>

#define FIO
#ifdef FIO
#define inchar			getchar_unlocked
#define outchar(x)		putchar_unlocked(x)

template<typename T> void input(T &x) {
	x = 0; register T c = inchar();
	while (((c < 48) || (c > 57)) && (c != '-')) c = inchar();
	bool neg = false; if (c == '-') neg = true;
	for (; c < 48 || c > 57; c = inchar());
	for (; c > 47 && c < 58; c = inchar()) x = (x << 3) + (x << 1) + (c & 15);
	if (neg) x = -x;
}
template<typename T> void output(T n) {
	if (n < 0) { outchar('-'); n *= -1; }
	char snum[65]; int i = 0;
	do {
		snum[i++] = n % 10 + '0';
		n /= 10;
	} while (n);
	i = i - 1;
	while (i >= 0) outchar(snum[i--]);
}
#else
char __cc;
#define input(x) cin >> x;
#define inchar() (cin>>__cc,__cc);
#define output(x) cout << x;
#define outchar(x) cout << x;
#endif

using namespace std;

typedef long long llong;

const int N = 3*1e5 + 10, M = 998244353, Z = (1<<25);
int a[N];
int qx[N]; 

pair<llong, int> ans1[N];
pair<int,int> sm2[N*2];

int bs[Z];

void set_bs(int v) {
    bs[v>>5]|=(1<<(v&31));
}
int query_bs(int v) {
    int v2 = (1<<(v&31));
    return (bs[v>>5]&v2)==v2;
}

const int DD[6] = {19,5,9,9,9};
int sm[6][N];

void mk(int z) {
    int s = 0;
    for (int j = 0; j < z; ++j) s += DD[j];
    for(int j = 0; j < (1<<DD[z]); ++j) {
        int cs = 0, cs2 = 0;
        for(int k = 0; k < DD[z]; ++k) {
            int k2 = 1<<k;
            if((j&k2)==k2) {
                cs = (cs+a[s+k])%M;
            }
        }
        sm[z][j] = cs;
    }
}

void mk_all() {
    for (int j = 0; j < 5; ++j) mk(j);
    for (int i = 0; i < (1 << DD[1]); ++i) {
        for(int j = 0; j < (1<<DD[0]); ++j) {
            int s = sm[0][j]+sm[1][i]; if(s>=M) s-=M;
            set_bs(s);
        }
    }
}

int solve1(int q) {
    int x = qx[q];
    int d0 = 1 << DD[0], d1 = 1 << DD[1], ds = DD[0] + DD[1];
    for (int k = 2; k < 5; ds += DD[k], ++k) {
        int dk = 1<<DD[k];
        for (int j = dk-1; j>=0; --j) {
            int ts = x+M-sm[k][j]; if (ts>=M) ts-=M;
            if(query_bs(ts)) {
                ans1[q] = {(1LL*j)<<ds,ts}; 
                return 1;
            }
        }
    }
    return 0;
}

void solve2(int q){
    int d0=1<<DD[0];
    for(int i=0;i<d0;++i){
        sm2[i]={sm[0][i],i};
    }
    sort(sm2,sm2+d0);
    
    for(int i=0;i<q;++i){
        for(int j=(1<<DD[1])-1;j>=0;--j){
            int ts=ans1[i].second+M-sm[1][j];
            if(ts>=M) ts-=M;
            if(query_bs(ts)){
                pair<int,int> p={ts,0};
                auto it=lower_bound(sm2,sm2+d0,p);
                if(it->first==ts){
                    ans1[i].first|=((j<<DD[0])|it->second);
                    break;
                }
            }
        }
    }
}
int main() {
	int n; input(n); //scanf("%d",&n);
    for(int i = 0; i <n; ++i) /*scanf("%d",&a0[i]);*/ input(a[i]);	
    
    for(int i=0;i<60;++i) a[i]=a[180+i];
    mk_all();
    
	int q; input(q); //scanf("%d",&q); 
    for(int i = 0; i <q; ++i) input(qx[i]); /*scanf("%d",&qx[i]);*/
	
	for(int i = 0; i < q; ++i) {
        int r = solve1(i);
        assert(r);
	}
	solve2(q);
	
	
	for(int i=0;i<q;++i){
	    llong b=ans1[i].first;
        //printf("0 0 0 %lld\n", b);
        output(0);outchar(' ');
        output(0);outchar(' ');
        output(0);outchar(' ');
        output(b); outchar('\n');
	}
	return 0;
}
