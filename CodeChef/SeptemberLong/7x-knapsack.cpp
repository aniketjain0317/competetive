// Problem
//

#include <bits/stdc++.h>
using namespace std;



#if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
#define _MATH_DEFINES_DEFINED

#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

#endif  /* _USE_MATH_DEFINES */


#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define vshow1d(arr) {int n = arr.size(); fr(i,0,n) {csp(arr[i]);}cout<<endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define vshow2d(arr) {int n=arr.size();   fr(i,0,n) {int m = arr[i].size(); fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define N 1e5
#define INF 1e9+5

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

int n=0;

int nii=0;
map <int,int> m1;
// A utility function that returns
// maximum of two integers
void display(vi p)
{
  int ans[nii]={};
  for(auto x: p) ans[x-1]=1;
  cout << "\"";
  for(auto x: ans) cout << x;
  cout << "\",";
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}
int K[49][(int)1e7]={};
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(
					val[i - 1] + K[i - 1][w - wt[i - 1]],
					K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

int knaparr(int wt[], int n, int w, vi p)
{
  // vshow1d(p);
  if(n==0)
  {
    // for(int i=0;i<p.size();i++) cout << p[i] << endl;
    display(p);
    return 1;
  }
  // else if(!K[n][w]) return 0;
  int next=0;
  for(int i =n;i>=0;i--)
  {
    if(K[n][w]==K[i][w]) continue;
    p.push_back(i+1);
    next=i;
    break;
  }
  knaparr(wt,next,w-wt[next],p);
  return 1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("input.txt","r",stdin);
  freopen("myans2.txt","w",stdout);
  int m = 0;
  n=37+m;
  int k = 4;
  int n2 = n-m;
  int wt[n-m]={};
  ll sumtt[n+1-m]={};
  frr(i,1,n2)
  {
    int j = 1;
    int i2 = i+m;
    fr(aarwd,0,k) j*=i2;
    wt[i-1]=j;
    sumtt[i]=sumtt[i-1]+j;
  }
  int sminus = 336 + 96*(n+1);
  int kminus = 768;
  int sum=sumtt[n2]/2-sminus-kminus;
	int sf = knapSack(sum, wt, wt, n2);
  vi p;
  // int cha[8]={8,9,11,12,14,15,18,21};
  // int opan[33]={};
  // for(auto x: cha) opan[x]=1;
  frr(i,n2,n2)
  {
    // if(!opan[i2]) {cout << "\"\","; continue;}
    // int i=i2+16;
    // cout << i << ": " << endl;
    nii=i;
    int sum=sumtt[i]/2-sminus-kminus;
    int sf = K[i][sum];
    knaparr(wt,i,sum,p);
    cout << (sumtt[i]-2*sf - 2*sminus - 2*kminus) << ",";
  }
	return 0;
}
