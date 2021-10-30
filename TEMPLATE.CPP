#include<bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define vvi             vector<vector<int>>
#define ld              long double
#define mod             1000000007
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vpii            vector<pair<int,int>>
#define fr(i,a,b)       for(int i = a; i < b; i += 1)
#define all(x)          x.begin(),x.end()
#define sz(a)           (int)(a.size())
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define input(a)        for(auto it = a.begin(); it != a.end(); it++) { int value; cin >> value; *it = value;}
#define print(a)        for(auto it = a.begin() ; it != a.end() ; it++){ cout << *it << " " ;}cout << '\n';
#define SS                      stringstream
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
 
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
 
// int power(int x ,int y )
// {
//     if( y == 0 )
//         return 1;
    
//     int temp = power(x,y/2);
    
//     if( y % 2 == 0 )
//         return temp*temp;
//     else
//         return x*temp*temp;
// }
 
// int fac[22001];
// int power(int x, int y, int p) 
// { 
//     int res = 1;      // Initialize result 
 
//     x = x % p;  // Update x if it is more than or 
//                 // equal to p 
 
//     while (y > 0) 
//     { 
//         // If y is odd, multiply x with result 
//         if (y & 1) 
//             res = (res*x) % p; 
 
//         // y must be even now 
//         y = y>>1; // y = y/2 
//         x = (x*x) % p; 
//     } 
//     return res; 
// } 
 
// // Returns n^(-1) mod p 
// int modInverse(int n, int p) 
// { 
//     return power(n, p-2, p); 
// } 
 
 
// // Returns nCr % p using Fermat's little 
// // theorem. 
// int nCrModPFermat(int n, int r, int p) 
// { 
//    // Base case 
//    if (r==0) 
//       return 1; 
 
//     // Fill factorial array so that we 
//     // can find all factorial of r, n 
//     // and n-r 
 
 
//   return (fac[n]* modInverse(fac[r], p) % p * 
//     modInverse(fac[n-r], p) % p) % p; 
// }
 
 
// struct info
// {
//     int x;
//     info () : x(0) {};
// };
 
// int *arr;
 
// struct SegTree
// {
//     int N;
//     vector<info> st;
 
//     SegTree(int n)
//     {
//         N = n;
//         st.resize(4 * N + 5);
//     }
 
//     void merge(info &cur, info &l, info &r)
//     {
//         cur.x = max(l.x, r.x);
//     }
 
//     void Build(int node, int L, int R)
//     {
//         if (L == R)
//         {
//             st[node].x = arr[L];
//             return;
//         }
//         int M = (L + R) / 2;
//         Build(node * 2, L, M);
//         Build(node * 2 + 1, M + 1, R);
//         merge(st[node], st[node * 2], st[node * 2 + 1]);
//     }
 
//     info Query(int node, int L, int R, int i, int j)
//     {
//         if (j < L || i > R)
//             return info();
//         if (i <= L && R <= j)
//             return st[node];
//         int M = (L + R) / 2;
//         info left = Query(node * 2, L, M, i, j);
//         info right = Query(node * 2 + 1, M + 1, R, i, j);
//         info cur;
//         merge(cur, left, right);
//         return cur;
//     }
 
//     void Update(int node, int L, int R, int pos, int val)
//     {
//         if (L == R)
//         {
//             st[node].x += val;
//             return;
//         }
//         int M = (L + R) / 2;
//         if (pos <= M)
//             Update(node * 2, L, M, pos, val);
//         else
//             Update(node * 2 + 1, M + 1, R, pos, val);
 
//         merge(st[node], st[node * 2], st[node * 2 + 1]);
//     }
 
//     info query(int l, int r) { return Query(1, 0, N, l, r); }
 
//     void update(int pos, int val) { Update(1, 0, N, pos, val); }
 
//     void build() { Build(1, 0, N); }
// };
 
// // vector<vector<pair<int, int>>> adj;
 
// // int dijkstra(int s)
// // {
 
// //     int n = adj.size();
// //     vi d(n, inf);
// //     vi p(n, -1);
 
// //     d[s] = 0;
// //     set<pair<int, int> > q;
// //     q.insert({0, s});
// //     while (!q.empty()) {
// //         int v = q.begin()->second;
// //         q.erase(q.begin());
 
// //         for (auto edge : adj[v]) {
// //             int to = edge.first;
// //             int len = edge.second;
 
// //             if (d[v] + len < d[to]) {
// //                 q.erase({d[to], to});
// //                 d[to] = d[v] + len;
// //                 p[to] = v;
// //                 q.insert({d[to], to});
// //             }
// //         }
// //     }
 
// //     if (d[n - 1] == inf)
// //         d[n - 1] = -1;
 
// //     return d[n - 1];
// // }

// int gcd(int a, int b)
// {
//     return (b == 0) ? a : gcd(b, a % b);
// }
 
// int lcm(int a, int b)
// {
//     return (a*b)/gcd(a,b);
// }
 

 
// void SieveOfEratosthenes(int n) 
// { 
//     bool prime[n+1]; 
//     memset(prime, true, sizeof(prime)); 
 
//     for (int p=2; p*p<=n; p++) 
//     { 
//         if (prime[p] == true) 
//         {  
//             for (int i=p*p; i<=n; i += p) 
//                 prime[i] = false; 
//         } 
//     } 
 
//     // Print all prime numbers 
//     for (int p=2; p<=n; p++) 
//        if (prime[p]) 
//           cout << p << " "; 
// } 
 
 
 
// vi primes;
 
//   void sieve ()
//   {
//     int i, j;
//     bitset <3200> bs;
//     bs.set();
//     bs[0]=bs[1]=0;
//     for (i=2; i<=3180; i++)
//     {
//         if (bs[i]==1)
//         {
//             for (j=i*i; j<=3180; j+=i)
//                 bs[j]=0;
//             primes.pb(i);
//         }
//     }
// }

// int kpar(int u, int k)
// {
//     int node = u;
//     for(int i = 24; i >= 0; i--)
//     {
//         if((1LL << i) <= k)
//         {
//             node = p[node][i];
//             k -= (1LL << i);
//         }
//     }
//     return node;
// }

// int lca(int a, int b)
// {
//     if(d[a] < d[b])
//         swap(a, b);

//     int req = d[a] - d[b];
//    // db(a, b);
//     a = kpar(a, req);
//     //db("new", a, b);
//     if(a == b)
//         return a;

//     for(int i = 24; i >= 0; i--)
//     {
//         if(p[a][i] != p[b][i])
//         {
//             a = p[a][i];
//             b = p[b][i];
//         }
//     }

//     return p[a][0];
// }

// vector<int> prefix_function (string Z) {
 
//     int n = (int) Z.length();
 
//     vector<int> F (n);
 
//      F[0]=0;
 
//     for (int i=1; i<n; ++i) {
 
//         int j = F[i-1];
 
//         while (j > 0 && Z[i] != Z[j])
 
//             j = F[j-1];
 
//         if (Z[i] == Z[j])  ++j;
 
//         F[i] = j;
 
//     }
 
//     return F;
 
// }
// vi Z(string s)
// {
//  int L = 0, R = 0;
// for (int i = 1; i < n; i++) 
// {
//     if (i > R) 
//     {
//         L = R = i;
//         while (R < n && s[R-L] == s[R]) 
//         {
//             R++;
//         }
//         z[i] = R-L; 
//         R--;
//     } 
//     else 
//     {
//         int k = i-L;
//         if (z[k] < R-i+1) 
//         {
//             z[i] = z[k];
//         } 
//         else 
//         {
//             L = i;
//             while (R < n && s[R-L] == s[R]) 
//             {
//                 R++;
//             }
//             z[i] = R-L; 
//             R--;
//         }
//     }
// }
//}

bool isPrime(int n)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    
    return true;
}

class union_find
{
 
public:
    int *pr;
    int *sz;
 
    union_find(int n)
    {
        pr = new int[n + 1];
        sz = new int[n + 1];
 
        for (int i = 1; i <= n; ++i)
            pr[i] = i, sz[i] = 1;
    }
 
    int root(int i)
    {
        if (pr[i] == i)
            return i;
 
        return pr[i] = root(pr[pr[i]]);
    }
 
    int find(int i, int j)
    {
        return (root(i) == root(j));
    }
 
    int un(int i, int j)
    {
        int u = root(i);
        int v = root(j);
 
        if (u == v)
            return 0;
 
        if (sz[u] < sz[v])
            swap(u, v);
 
        pr[v] = u;
        sz[u] += sz[v];
 
        return 1;
    }
};



// int a[N * 3];   // this array stors the nodes;
// vector<int> st; //this vector represents the tree;
// class segmenttree 
// {
//     void init(int _n) 
//     {
//         st.clear();
//         st.resize(4 * _n, INT_MIN);
//     }
//     void merge(lint l,int r)
//     {
//         return l+r;     //change here accordingly;
//     }
//     void build(ll l, ll r, ll node) 
//     {
//         if (l == r) 
//         {
//             st[node] = a[l];
//             return;
//         }
//         ll mid = (l + r) / 2;
//         build(l, mid, node * 2 + 1);
//         build(mid + 1, r, node * 2 + 2);
//         st[node] = merge(st[2 * node + 1], st[2 * node + 2]);
//     }
 
//     void update(ll l, ll r, ll indup, ll val, ll node) 
//     {
//         if (l == r) 
//         {
//             a[l] = val;
//             st[node] = val;
//             return;
//         }
//         else 
//         {
//             ll mid = (l + r) / 2;
//             if (indup >= l && indup <= mid) 
//             {
//                 update(l, mid, indup, val, node * 2 + 1);
//             }
//             else 
//             {
//                 update(mid + 1, r, indup, val, node * 2 + 2);
//             }
//             st[node] = merge(st[2 * node + 1], st[2 * node + 2]);
//         }
//     }
 
//     ll query(ll si, ll se, ll l, ll r, ll node) 
//     {
//         if (se < l || si > r || l > r)
//             return 0;       //change here accordingly;
//         if (si >= l && se <= r)
//             return st[node];
//         ll mid = (si + se) / 2;
//         ll q1 = query(si, mid, l, r, node * 2 + 1);
//         ll q2 = query(mid + 1, se, l, r, node * 2 + 2);
//         return merge(q1, q2);
//     }
// };

// void build(int node, int start, int end)
// {
//     if(start == end)
//     {
//         // Leaf node will have a single element
//         tree[node] = A[start];
//     }
//     else
//     {
//         int mid = (start + end) / 2;
//         // Recurse on the left child
//         build(2*node, start, mid);
//         // Recurse on the right child
//         build(2*node+1, mid+1, end);
//         // Internal node will have the sum of both of its children
//         tree[node] = tree[2*node]^tree[2*node+1];
//     }
// }

// void update(int node, int start, int end, int idx, int val)
// {
//     if(start == end)
//     {
//         // Leaf node
//         A[idx] = val;
//         tree[node] = val;
//     }
//     else
//     {
//         int mid = (start + end) / 2;
//         if(start <= idx and idx <= mid)
//         {
//             // If idx is in the left child, recurse on the left child
//             update(2*node, start, mid, idx, val);
//         }
//         else
//         {
//             // if idx is in the right child, recurse on the right child
//             update(2*node+1, mid+1, end, idx, val);
//         }
//         // Internal node will have the sum of both of its children
//         tree[node] = tree[2*node]^tree[2*node+1];
//     }
// }

// int query(int node, int start, int end, int l, int r)
// {
//     if(r < start or end < l)
//     {
//         // range represented by a node is completely outside the given range
//         return 0;
//     }
//     if(l <= start and end <= r)
//     {
//         // range represented by a node is completely inside the given range
//         return tree[node];
//     }
//     // range represented by a node is partially inside and partially outside the given range
//     int mid = (start + end) / 2;
//     int p1 = query(2*node, start, mid, l, r);
//     int p2 = query(2*node+1, mid+1, end, l, r);
//     return p1^p2;
// }


// //--10--
// //__FENWICK TREE___
// struct fenwick 
// {
//     vector<int> fn;
//     int n;
//     fenwick(){}
//     fenwick(int n) 
//     {
//         init(n);
//     }
//     void init(int _n) 
//     {
//         n = _n + 10;
//         fn.clear(); fn.resize(n, 0);
//     }
//     void update(int x, int val) 
//     {
//         x++;
//         while (x < n) 
//         {
//             fn[x] += val;
//             x += (x & (-x));
//         }
//     }
//     int query(int x) 
//     {
//         x++;
//         int ans = 0;
//         while (x) 
//         {
//             ans += fn[x];
//             x -= (x & (-x));
//         }
//         return ans;
//     }
//     int sum(int l, int r) 
//     {
//         return sum(r) - sum(l - 1);
//     }
// };


// //----11-dijiktra------
// vll dijiktras(vpll adj[], ll V, ll src) 
// { 
//     priority_queue< pll, vpll , greater<pll> > pq;
//     vector<ll> dist(V,1e18);
//     pq.push(make_pair(0, src)); 
//     dist[src] = 0; 
//     while (!pq.empty()) 
//     { 
//         ll u = pq.top().second; 
//         pq.pop();  
//         for (auto x : adj[u]) 
//         { 
//             ll v = x.first; 
//             ll weight = x.second; 
//             if (dist[v] > dist[u] + weight) 
//             { 
//                 dist[v] = dist[u] + weight; 
//                 pq.push(make_pair(dist[v], v)); 
//             } 
//         } 
//     } 
//     return dist;
// }

struct SegTree
{
    vi tree, a, lazy;       //0-based indexing for a

    int build (int node, int l, int r)
    {
        if (l==r)
            return tree[node]=a[l];
        return tree[node]=min(build(2*node, l, (l+r)/2), build(2*node+1, (l+r)/2+1, r));   //Type of segment tree
    }

    SegTree(vi arr)
    {
        a=arr;
        tree=vi(a.size()*4);
        lazy=vi(a.size()*4);                    //Type of range update
        build(1, 0, a.size()-1);
    }

    void lazy_prop (int node)
    {
        if (lazy[node]==0)
            return;
        tree[node]+=lazy[node];                 //Type of range update
        if (2*node<lazy.size())
            lazy[2*node]+=lazy[node];               //Type of range update
        if (2*node+1<lazy.size())
            lazy[2*node+1]+=lazy[node];             //Type of range update
        lazy[node]=0;
    }

    int r_query (int node, int l, int r, int reql, int reqr)
    {
        int p1, p2;
        lazy_prop(node);
        if (l>reqr || r<reql)
            return -1;
        if (reql<=l && r<=reqr)
            return tree[node];
        p1=r_query(2*node, l, (l+r)/2, reql, reqr);
        p2=r_query(2*node+1, (l+r)/2+1, r, reql, reqr);
        if (p1==-1)
            return p2;
        if (p2==-1)
            return p1;
        return min(p1,p2);                      //Type of segment tree
    }

    void p_update(int node, int l, int r, int index, int del)
    {
        lazy_prop(node);
        if (l==r)
        {
            tree[node]+=del;                    //Type of point update
            return;
        }
        if (index<=(l+r)/2)
        {
            p_update(2*node, l, (l+r)/2, index, del);
            lazy_prop(2*node+1);
            tree[node]=min(tree[2*node], tree[2*node+1]);//Type of segment tree
        }
        else
        {
            p_update(2*node+1, (l+r)/2+1, r, index, del);
            lazy_prop(2*node);
            tree[node]=min(tree[2*node], tree[2*node+1]);//Type of segment tree
        }
    }

    void r_update(int node, int l, int r, int reql, int reqr, int del)
    {
        lazy_prop(node);
        if (l>reqr || r<reql)
            return;
        if (reql<=l && r<=reqr)
        {
            lazy[node]+=del;                    //Type of range update
            lazy_prop(node);
            return;
        }
        r_update(2*node, l, (l+r)/2, reql, reqr, del);
        r_update(2*node+1, (l+r)/2+1, r, reql, reqr, del);
        tree[node]=min(tree[2*node], tree[2*node+1]);   //Type of segment tree
    }
};

struct FenTree
{
    vi tree, a;
public:
    FenTree(int n)
    {
        tree=a=vi(n+1);     //One-based indexing
    }
 
    void update (int i, int del)
    {
        a[i]+=del;
        while (i<a.size())
        {
            tree[i]+=del;
            i+=(i&(-i));
        }
    }
 
    int sum(int i)
    {
        int s=0;
        while (i)
        {
            s+=tree[i];
            i-=(i&(-i));
        }
        return s;
    }
 
    int RSQ (int i, int j)
    {
        if (i>j)
            return 0;
        return sum(j)-sum(i-1);
    }
};

void FASTIO()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int mxN = 2e5 + 100;
int n, a, b, c, x, y , z;
int ans;


bool isVowel(char x)
{
    return x == 'A' or x == 'E' or x == 'I' or x == 'O' or x == 'U';
}

bool left(char ch)
{
    return ch == 'F' or ch == 'O';
}

bool right(char ch)
{
    return ch == 'X' or ch == 'F';
}

void test_case()
{
    int n;
    string s;
    cin >> n >> s;
    int dp[n][2];
    for(int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = 1e9;
    }
    
    if(left(s[0])) {
        dp[0][0] = 0;
    } 
    
    if(right(s[0]))
    {
        dp[0][1] = 0;
    }
    
    for(int i = 1; i < n; i++) {
        
        if(left(s[i])) 
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
            dp[i][0] = min(dp[i - 1][0], dp[i][0]);
        } 
        
        if(right(s[i]) )
        {
            dp[i][1] = min(dp[i][1], dp[i-1][1]);   
            dp[i][1] = min(dp[i][1], dp[i-1][0] + 1);
        }
    }
    
    cout << min(dp[n-1][0], dp[n-1][1]) << '\n';
    
    
}

 
int32_t main()
{
    FASTIO();
 
    int t;
    t = 1;
    cin >> t;
 
    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        test_case();
    }
    return 0;
} 