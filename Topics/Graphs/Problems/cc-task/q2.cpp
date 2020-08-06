// Problem 2
//Done (djikstra)

/* IO FORMAT
INPUT:
n m
(m lines of (a,b,c) where a,b are vertices and c is the weight) (a,b -> 1-n)
s

OUTPUT:
(n numbers: every user's strength with the s user)
(to calculate upto only k vagueness, we do bfs to find distance, then only print those whose dist is <=k)
*/

#include <bits/stdc++.h>
using namespace std;

// #if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
// #define _MATH_DEFINES_DEFINED
// #define M_E        2.71828182845904523536
// #define M_LOG2E    1.44269504088896340736
// #define M_LOG10E   0.434294481903251827651
// #define M_LN2      0.693147180559945309417
// #define M_LN10     2.30258509299404568402
// #define M_PI       3.14159265358979323846
// #define M_PI_2     1.57079632679489661923
// #define M_PI_4     0.785398163397448309616
// #define M_1_PI     0.318309886183790671538
// #define M_2_PI     0.636619772367581343076
// #define M_2_SQRTPI 1.12837916709551257390
// #define M_SQRT2    1.41421356237309504880
// #define M_SQRT1_2  0.707106781186547524401
// #endif
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define N 1000
#define INF 100000
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;


#define bd(a,b,c,adj) adj[a-1].pb(mp(c,b-1)); adj[b-1].pb(mp(c,a-1));
#define ud(a,b,c,adj) adj[a-1].pb(mp(c,b-1));


vector<vpi> adj;
vi dist;

void djikstra(int s);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("myans.txt","w",stdout);
  // freopen("input.txt","r",stdin);
  int n,m; cin >> n >> m;
  adj.resize(n);
  dist.resize(n,0);
  fr(i,0,m)
  {
    int a,b,c; cin >> a >> b >> c;
    bd(a,b,c,adj);
  }

  int s; cin >> s;
  djikstra(--s);
  vshow1d(dist);
}

void djikstra(int s)
{
   priority_queue<pi,vpi> pq;
   pq.push(mp(1,s));
   dist[s]=1;
   while(!pq.empty())
   {
     pi node=pq.top();
     pq.pop();
     for(auto child: adj[node.sn])
     {
       int v=child.sn;
       int nwt = dist[node.sn]*child.fs;
       if(dist[v]<nwt)
       {
         dist[v]=nwt;
         pq.push(mp(dist[v],v));
       }
     }
   }
}
