// Problem
//

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define bs binary_search
#define fs first
#define sn second
#define gri greater<int>
#define cnl(x) cout << x << endl
#define csp(x) cout << x << " "
#define read(x) cin >> x
#define all(v) v.begin(),v.end()
#define mxs(m,a) m=max(m,a)
#define mns(m,a) m=min(m,a)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=a;i<=b;i++)
#define frrb(i,a,b) for(int i=a; i>=b;i--)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define ainp(n,arr) int n; read(n); int arr[n]; cinp(n,arr);
#define ainpl(n,arr) ll n; read(n); ll arr[n]; cinp(n,arr);
#define cinp(n,arr) fr(i,0,n) read(arr[i]);
#define showVI(arr) {for(auto &xxx: arr) csp(xxx); cout << endl;}
#define show1d(n,arr) fr(i,0,n) {csp(arr[i]);}cout<<endl;
#define showVVI(arr) {for(auto &vvv: arr) {for(auto &xxxx: vvv) csp(xxxx); cout << endl;}}
#define show2d(n,m,arr) {fr(i,0,n) {fr(j,0,m) csp(arr[i][j]); cout << endl;}}
#define intt int32_t
#define int long long
// #define endl '\n'

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll INF = 1000000007;
const int N = 100005;

string makeString(vector<int>& a){
	string s;
	s += to_string(a[0]);
	for(int i = 1;i<a.size();i++){
		s.pb('.');
		s +=  to_string(a[i]);
	}
	return s;
}
intt main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    test(t)
    {
      int n,m;
  		vector<int> a;
  		cin>>n;
  		int x = 0;
  		cin>>x;
  		a.pb(x);
  		cout<<makeString(a)<<endl;
  		for(int i = 1;i<n;i++){
  			cin>>x;
  			if(x == 1){
  				a.pb(x);
  			}
  			else{
  				while(a.back() + 1 != x){
  					a.pop_back();
  				}
  				a.pop_back();
  				a.pb(x);
  			}
  			cout<<makeString(a)<<endl;
  		}
    }
}
