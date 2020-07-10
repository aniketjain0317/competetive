// Problem
//

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
// #define int int16_t;
// #define ll int64_t;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;


#define bd(a,b,adj) adj[a-1].pb(b-1); adj[b-1].pb(a-1);
#define ud(a,b,adj) adj[a].pb(b);

vi adj[2][N];
vi tree[2][N];
int visited[2][N]={};

void dfs(int node, int k);
vi treeCenters(int n, int k);
string encode(int root, int k);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  int n[2];
  vi center[2];
  string s[2];
  fr(k,0,2)
  {
    cin >> n[k];
    fr(i,0,n[k]-1) {int a,b; cin >> a >> b; bd(a,b,adj[k]);}
    center[k]=treeCenters(n[k],k);
  }
  if(n[1]!= n[2]) {cnl("NOT");return 0;}
  dfs(center[0][0],0);
  s[0] = encode(center[0][0],0);
  int flag=0;
  for(auto c: center[1])
  {
    dfs(c,1);
    s[1]= encode(c,1);
    if(s[0]==s[1]) {flag=1;break;}
    fr(i,0,n[1]) {tree[1][i].clear(); visited[1][i]=0;}
  }
  if(flag) cnl("ISO");
  else cnl("NOT");
}

void dfs(int node, int k)
{
  visited[k][node]=1;
  for(auto child: adj[k][node])
  {
    if(!visited[k][child])
    {
      tree[k][node].pb(child);
      dfs(child,k);
    }
  }
}

vi treeCenters(int n, int k)
{
  vi leaves;
  int nbs[n]={};
  fr(i,0,n) {nbs[i]=adj[k][i].size(); if(nbs[i]==1) leaves.pb(i);}
  int count = leaves.size();
  while(count<n)
  {
    for(auto x: leaves) {for(auto y: adj[k][x]) nbs[y]--; nbs[x]=-1;}
    leaves.clear();
    fr(i,0,n) if(nbs[i]==1) leaves.pb(i);
    if(leaves.empty()) fr(i,0,n) if(nbs[i]==0) leaves.pb(i);
    count+=leaves.size();
    // show1d(n,nbs);
  }
  return leaves;
}

string encode(int root, int k)
{
  vector<string> labels;
  // if(tree[k][root].empty()) return "()";
  for(auto child: tree[k][root])
  {
    labels.pb(encode(child,k));
  }
  sort(labels.begin(),labels.end());
  string ans="(";
  for(auto lb: labels) ans+=lb;
  ans+=")";
  return ans;
}
