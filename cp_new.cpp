#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifndef ONLINE_JUDGE
#include "debug_utils.h"
#else
#define debug(...) 37
#endif

using namespace __gnu_pbds;
using namespace std;
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
#define oi             oset<int>
#define opii           oset<pii>
#define gcd            __gcd
#define F              first
#define I              insert
#define S              second
#define lb             lower_bound
#define ub             upper_bound
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
#define cksubs(s,d)    (s.find(d) != string::npos)
#define py             cout<<"YES"<<endl
#define pn             cout<<"NO"<<endl
#define Shivam_Saurabh ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int lcm(int a, int b)  {return ((a * b) / gcd(a, b));}
bool iseven(int n)  {if ((n & 1) == 1) return false; else return true;}
bool isodd(int n)    {if ((n & 1) == 1) return true; else return false;}
vi pS(vi &v)  {vi ans((int)v.size()); for (int i = 0; i < (int)v.size(); i++) {if (i == 0) ans[i] = v[i]; else ans[i] = ans[i - 1] + v[i];} return ans;}
vi rpS(vi &v) {int n = v.size(); if (n <= 1)return v; vi ans(n); ans.back() = v.back(); for (int i = n - 2; i >= 0; --i) {ans[i] = ans[i + 1] + v[i];} return ans;}
vi helpmepls(vi &b) {vi v; int prv = -1; for (int it : b) {if (it != prv)v.eb(1); else v.back()++; prv = it;} return v;}
void pV(vi &v)   {if (v.size() == 0) {cout << endl; return;} int n = (int)v.size(); for (int i = 0; i < n; i++)cout << v[i] << " \n"[i == n - 1];}
int binpowm(int a, int b, int m) {a %= m; int res = 1; while (b > 0) {if (b & 1) res = res * a % m; a = a * a % m; b >>= 1;} return res;}
int vsum(int x, int y, vi &pS) {if (x == 0) return pS[y]; else return (pS[y] - pS[x - 1]);}
int binpow(int a, int b)  {int res = 1; while (b > 0) {if (b & 1)res = res * a; a = a * a; b >>= 1;} return res;}
int roof(int a, int b) {if (a % b == 0) return a / b; else return (a / b + 1);}
int highestBit(int n) {int _ = log2(n); return _;}
int xorUpToN(int n) { return (n % 4 == 0) ? n : (n % 4 == 1) ? 1 : (n % 4 == 2) ? n + 1 : 0; }

template <typename T>     using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>     using minh = priority_queue<T, vector<T>, greater<T>>;
template <typename T>     using maxh = priority_queue<T, vector<T>>;
template<class T>         bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T>         bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int md = 1000000007;
const int mmd = 998244353;
const long long pinf = 1000000000000000001;
const long long ninf = -1000000000000000001;

mt19937 rng(steady_clock::now().time_since_epoch().count());

void solve() {
}

int32_t main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif

    Shivam_Saurabh;

    cout << fixed << setprecision(18);
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
