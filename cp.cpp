#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

#define int            long long
#define ull            unsigned long long
#define float          long double
#define mp             make_pair
#define pii            pair<int, int>
#define pip            pair<int, pii>
#define ppi            pair<pii, int>
#define vi             vector<int>
#define vvi            vector<vi>
#define si             set<int>
#define dsi            set<int, greater<int>>
#define msi            multiset<int>
#define mii            map<int, int>
#define dmii           map<int, int, greater<int> >
#define vpii           vector<pii>
#define vvpii          vector<vpii>
#define spii           set<pii>
#define gcd            __gcd
#define F              first
#define I              insert
#define S              second
#define lb             lower_bound
#define ub             upper_bound
#define endl           "\n"
#define eb             emplace_back
#define pb             push_back
#define fbo            find_by_order
#define ook            order_of_key
#define maxel          max_element
#define minel          min_element
#define in(x)          int (x);cin>>(x)
#define inv(v,n)       vi (v)(n);iforls(i,(n)) cin>>v[i]
#define sin(x)         string (x);cin>>(x)
#define cin(x)         char (x);cin>>(x)
#define ftl(x)         begin(x),end(x)
#define ltf(x)         rbegin(x),rend(x)
#define setbits(x)     __builtin_popcountll(x)
#define endzeroes(x)   __builtin_ctzll(x)
#define make_unique(x) sort(ftl((x))); (x).resize(unique(ftl((x))) - (x).begin())
#define r_rotate(x,i)  rotate((x).begin(), (x).begin()+(x).size()-(i), (x).end())
#define l_rotate(x,i)  rotate((x).begin(), (x).begin()+(i), (x).end())
#define iforl(i, a, b) for (int i=(a); i<(b); i++)
#define iforls(i, a)   for (int i=0; i<(a); i++)
#define dforl(i, b, a) for (int i = (b); i >= (a); i--)
#define dforls(i, a)   for (int i = (a); i >= 0; i--)
#define cksubs(s,d)    (s.find(d) != string::npos)
#define py             cout<<"YES"<<endl
#define pn             cout<<"NO"<<endl
#define Shivam_Sbh     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int xorv (vi &v)  {int a = v[0]; for (int i = 1; i < (int)v.size(); i++)   a = (a ^ v[i]);     return a;}
int andv (vi &v)  {int a = v[0]; for (int i = 1; i < (int)v.size(); i++)   a = (a & v[i]);     return a;}
int orv  (vi &v)  {int a = v[0]; for (int i = 1; i < (int)v.size(); i++)   a = (a | v[i]);     return a;}
int gcdv (vi &v)  {int a = v[0]; for (int i = 1; i < (int)v.size(); i++)   a = gcd(a, v[i]);   return a;}
int lcm(int a, int b)  {return ((a * b) / gcd(a, b));}
int lcmv (vi &v)   {int a = v[0]; for (int i = 1; i < (int)v.size(); i++)   a = lcm(a, v[i]);   return a;}
bool iseven(int n)  {if ((n & 1) == 1) return false; else return true;}
bool isodd(int n)    {if ((n & 1) == 1) return true; else return false;}
bool ispowof2(int n)   {if (n == 0) return false; else { if (n & (n - 1)) return false; else return true;}}
vi pS(vi &v)  {vi ans((int)v.size()); for (int i = 0; i < (int)v.size(); i++) {if (i == 0) ans[i] = v[i]; else ans[i] = ans[i - 1] + v[i];} return ans;}
vi helpmepls(string &b) {vi v; int prv = -1; for (int it : b) {if (it != prv)v.eb(1); else v.back()++; prv = it;} return v;}
void pV(vi &v)   {if (v.size() == 0) {cout << endl; return;} int n = (int)v.size(); for (int i = 0; i < n; i++)cout << v[i] << " \n"[i == n - 1];}
int binpowm(int a, int b, int m) {a %= m; int res = 1; while (b > 0) {if (b & 1) res = res * a % m; a = a * a % m; b >>= 1;} return res;}
int vsum(int x, int y, vi &pS) {if (x == 0) return pS[y]; else return (pS[y] - pS[x - 1]);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int gcdExtended(int a, int b, int *x, int *y) {if (a == 0) {*x = 0, *y = 1; return b;} int x1, y1; int gcd = gcdExtended(b % a, a, &x1, &y1); *x = y1 - (b / a) * x1; *y = x1; return gcd;}
int modInverse(int b, int m) {int x, y; int g = gcdExtended(b, m, &x, &y); if (g != 1)return -1; return (x % m + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; int inv = modInverse(b, m); return ((inv * a) % m);}
int binpow(int a, int b)  {int res = 1; while (b > 0) {if (b & 1)res = res * a; a = a * a; b >>= 1;} return res;}
int roof(int a, int b) {if (a % b == 0) return a / b; else return (a / b + 1);}
void add_edge(vvi &v , int x, int y, bool z = false) {v[x].eb(y); if (!z)v[y].eb(x); return;}
void remove_edge(vvi &adj, int u, int v) { adj[u].erase(find(ftl(adj[u]), v)), adj[v].erase(find(ftl(adj[v]), u));}
int ncr(int n, int r, int p) {if (n < r)return 0; if (r == 0)return 1; int fac[n + 1]; fac[0] = 1; for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p; return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;}

template <typename T>     using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>     using minh = priority_queue<T, vector<T>, greater<T>>;
template <typename T>     using maxh = priority_queue<T, vector<T>>;
template<class T>         bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T>         bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <typename T>     ostream &operator<<(ostream &out, const vector<T> &v) { for (const auto &x : v) out << x << ' '; return out; }
template <typename T>     istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }

#ifndef ONLINE_JUDGE
#define debug(x)       cerr << #x <<" "; _print(x); cerr << endl
#else
#define debug(x)
#endif

void _print(bool x)               {cerr << (x ? "True" : "False");}
template <typename T>             void _print(T t) {cerr << t;}
template <typename T>             void _print(maxh<T> _);
template <typename T>             void _print(minh<T> _);
template <typename T, typename V> void _print(pair <T, V> p);
template <typename T>             void _print(vector <T> v);
template <typename T>             void _print(oset <T> v);
template <typename T>             void _print(queue<T> _);
template <typename T>             void _print(stack<T> _);
template <typename T>             void _print(set <T> v);
template <typename T, typename V> void _print(map <T, V> v);
template <typename T>             void _print(multiset <T> v);
template <typename T, typename V> void _print(pair <T, V> p) {cerr << "("; _print(p.F); cerr << ","; _print(p.S); cerr << ")";}
template <typename T>             void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T>             void _print(set <T> v) {cerr << "( "; for (T i : v) {_print(i); cerr << " ";} cerr << ")";}
template <typename T>             void _print(multiset <T> v) {cerr << "( "; for (T i : v) {_print(i); cerr << " ";} cerr << ")";}
template <typename T, typename V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T>             void _print(oset <T> v) {cerr << "( "; for (T i : v) {_print(i); cerr << " ";} cerr << ")";}
template <typename T>             void _print(maxh<T> _) {maxh<T> v = _; cerr << "{ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "}";}
template <typename T>             void _print(minh<T> _) {minh<T> v = _; cerr << "{ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "}";}
template <typename T>             void _print(queue<T> _) {queue<T> v = _; cerr << "{ "; while (!v.empty()) {_print(v.front()); cerr << " "; v.pop();} cerr << "}";}
template <typename T>             void _print(stack<T> _) {stack<T> v = _; cerr << "{ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "}";}

const int md = 1000000007;
const int mmd = 998244353;
const long long pinf = 1000000000000000001;
const long long ninf = -1000000000000000001;

mt19937 rng(steady_clock::now().time_since_epoch().count());

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0 , 0};

void solve() {
}

int32_t main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif

    Shivam_Sbh;

    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);

    auto start = chrono::high_resolution_clock::now();

    int no_of_test = 1;
    cin >> no_of_test;
    iforls(test_no, no_of_test) {

#ifndef ONLINE_JUDGE
        cerr << "Test Case # " << test_no + 1 << endl;
#endif
        solve();
    }

#ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cerr << "Time Elapsed : " << ((long double)duration.count()) / ((long double) 1e9) << "s " << endl;
#endif

}
