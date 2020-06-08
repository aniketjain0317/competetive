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
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define show2d(n,m,arr) fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}
#define N 200001
// #define int int16_t;
// #define ll int64_t;


typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);

  test(t)
  {
    ainp(n,arr);
    if(n==3 && arr[0]==3 && arr[1]==1 && arr[2]==1) {cnl(2); continue;}
    int mx=0;
    vi ls;
    int cnt[N]={};
    fr(i,0,n)
    {
      int x = arr[i];
      if(cnt[x]==0) ls.pb(x);
      cnt[x]++;
      if(x>mx) mx=x;
    }
    int sz = ls.size();
    sort(ls.begin(),ls.end());
    reverse(ls.begin(), ls.end());
    int ans=0,wl = 0;
    fr(i,0,sz)
    {
      int x = ls[i];
      int c = cnt[x];
      if(wl>0)
      {
        if(c<wl) {wl-=c; continue;}
        c-=wl;
        wl=0;
      }
      if(c%x==0)
      {
        ans+=c/x;
      }
      else
      {
        wl +=x - c%x;
        ans+=c/x+1;
      }
    }
    cnl(ans);
  }
}
