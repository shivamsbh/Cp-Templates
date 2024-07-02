
//उद्यमेन हि सिध्यन्ति

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

#define int            long long
#define ll             long long
#define ull            unsigned long long
#define float          long double
#define mp             make_pair
#define pii            pair<int, int>
#define pip            pair<int, pii>
#define ppi            pair<pii, int>
#define vi             vector<int>
#define vvi            vector<vi>
#define usi            unordered_set<int>
#define si             set<int>
#define dsi            set<int, greater<int>>
#define msi            multiset<int>
#define mii            map<int, int>
#define dmii           map<int, int, greater<int> >
#define umii           unordered_map<int, int>
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
#define ef             emplace_front
#define pb             push_back
#define pf             push_front
#define ppb            pop_back()
#define ppf            pop_front()
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

void _print(bool x)               {cerr << (x ? "True" : "False");}
template <typename T>             void _print(T t) {cerr << t;}
template <typename T>             void _print(maxh<T> _);
template <typename T>             void _print(minh<T> _);
template <typename T, typename V> void _print(pair <T, V> p);
template <typename T>             void _print(vector <T> v);
template <typename T>             void _print(oset <T> v);
template <typename T>             void _print(set <T> v);
template <typename T, typename V> void _print(map <T, V> v);
template <typename T, typename V> void _print(unordered_map <T, V> v);
template <typename T>             void _print(multiset <T> v);
template <typename T, typename V> void _print(pair <T, V> p) {cerr << "("; _print(p.F); cerr << ","; _print(p.S); cerr << ")";}
template <typename T>             void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T>             void _print(set <T> v) {cerr << "( "; for (T i : v) {_print(i); cerr << " ";} cerr << ")";}
template <typename T>             void _print(multiset <T> v) {cerr << "( "; for (T i : v) {_print(i); cerr << " ";} cerr << ")";}
template <typename T>             void _print(unordered_set <T> v) {cerr << "( "; for (T i : v) {_print(i); cerr << " ";} cerr << ")";}
template <typename T, typename V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T, typename V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T>             void _print(oset <T> v) {cerr << "( "; for (T i : v) {_print(i); cerr << " ";} cerr << ")";}
template <typename T>             void _print(maxh<T> _) {maxh<T> v = _; cerr << "{ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "}";}
template <typename T>             void _print(minh<T> _) {minh<T> v = _; cerr << "{ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "}";}
template <typename T>             void _print(queue<T> _) {queue<T> v = _; cerr << "{ "; while (!v.empty()) {_print(v.front()); cerr << " "; v.pop();} cerr << "}";}
template <typename T>             void _print(stack<T> _) {stack<T> v = _; cerr << "{ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << "}";}

#ifndef ONLINE_JUDGE
#define debug(x)       cerr << #x <<" "; _print(x); cerr << endl
#else
#define debug(x)
#endif

const int md = 1000000007;
const int mmd = 998244353;
const long long pinf = 1000000000000000001;
const long long ninf = -1000000000000000001;

mt19937 rng(steady_clock::now().time_since_epoch().count());

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0 , 0};

vi minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.eb(i);
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

const int32_t MOD = md;

struct mi {
    ll v; explicit operator ll() const { return v; }
    mi() { v = 0; }
    mi(ll _v) {
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mi& a, const mi& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const mi& a, const mi& b) {
        return !(a == b);
    }
    friend bool operator<(const mi& a, const mi& b) {
        return a.v < b.v;
    }

    mi& operator+=(const mi& m) {
        if ((v += m.v) >= MOD) v -= MOD;
        return *this;
    }
    mi& operator-=(const mi& m) {
        if ((v -= m.v) < 0) v += MOD;
        return *this;
    }
    mi& operator*=(const mi& m) {
        v = v * m.v % MOD; return *this;
    }
    mi& operator/=(const mi& m) { return (*this) *= ___(m); }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans;
    }
    friend mi ___(const mi& a) {
        assert(a.v != 0);
        return pow(a, MOD - 2);
    }

    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    mi operator++(int32_t) { mi temp; temp.v = v++; return temp; }
    mi operator--(int32_t) { mi temp; temp.v = v--; return temp; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mi& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mi& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};

vector<mi> fact;
void factorial() {
    fact.eb(1);
    for (int i = 1; i <= (int)2e5; i++)
        fact.eb(i * fact[i - 1]);
}

#define vmi  vector<mi>
#define vvmi vector<vmi>
#define vvvmi vector<vvmi>

struct DS {
    vector<int> par, sizz;
    int no_comp, max_csize = 1;
    DS(int n) : par(n), sizz(n, 1) {
        iota(par.begin(), par.end(), 0);
        no_comp = n;
    }
    int leader(int x) {
        if (par[x] == x)
            return x;
        else
            return (par[x] = leader(par[x]));
    }
    bool is_connected(int x, int y) {
        return (leader(x) == leader(y));
    }
    int size(int x) {
        return sizz[leader(x)];
    }
    bool merge(int x, int y) {
        int x_ = leader(x);
        int y_ = leader(y);
        if (x_ == y_)
            return false;
        no_comp--;
        if (size(x_) < size(y_))
            swap(x_, y_);
        sizz[x_] += sizz[y_];
        max_csize = max(max_csize, sizz[x_]);
        par[y_] = leader(x_);
        return true;
    }
};

int Prims(int n, vector<vector<pair<int, int>>> &adj) {
    int x, y, wt = LLONG_MAX;
    for (int a = 0; a < n; a++) {
        for (auto it : adj[a]) {
            int b = it.first; int w = it.second;
            if (wt > w) {
                x = a; y = b;
                wt = w;
            }
        }
    }
    int ans = wt;
    int edges = 1;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> m;
    vector<int> vis(n);
    vis[x] = 1;
    vis[y] = 1;
    for (auto it : adj[x]) {
        if (!vis[it.first])
            m.push(make_pair(it.second, make_pair(x, it.first)));
    }
    for (auto it : adj[y]) {
        if (!vis[it.first])
            m.push(make_pair(it.second, make_pair(y, it.first)));
    }
    while (!m.empty()) {
        pair<int, pair<int, int>> t = m.top();
        m.pop();
        if (vis[t.second.second])
            continue;
        ans += t.first;
        int _o_ = t.second.second;
        edges++;
        vis[_o_] = 1;
        for (auto it : adj[_o_]) {
            if (!vis[it.first])
                m.push(make_pair(it.second, make_pair(_o_, it.first)));
        }
        if (edges == n - 1)
            break;
    }
    if (edges == n - 1)
        return ans;
    else
        return -1;
}

/*
Template for Shortest path through bfs algorithm
It return shortest path from source to destination in vector(0 based indexing)
and and empty vector if path doest exist
*/

vector<int> spbfs(vector<vector<int>> &v, int from, int to)
{
    vector<int> path(v.size());
    vector<int> vis(v.size());
    queue<int> q;
    q.push(from);
    vis[from] = 1;
    int dist = -1;
    while (!q.empty()) {
        int queue_size = q.size();
        dist++;
        for (int i = 0; i < queue_size; i++) {
            int curNode = q.front();
            q.pop();
            if (curNode == to) {
                vector<int> v;
                int node = to;
                v.emplace_back(node );
                while (node  != from) {
                    node  = path[node];
                    v.emplace_back(node);
                }
                reverse(v.begin(), v.end());
                return v;
            }
            for (auto it : v[curNode]) {
                if (vis[it] != 1) {
                    path[it] = curNode;
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    return{};
}

int kadane(vi &____)
{
    int _ = INT_MIN, __ = 0;

    iforls(i, (int)____.size()) {
        __ = __ + ____[i];
        if (_ < __)
            _ = __;

        if (__ < 0)
            __ = 0;
    }
    return _;
}

struct DSK {
    vector<int> par, sizz;
    int no_comp, max_csize = 1;
    DSK(int n) : par(n), sizz(n, 1) {
        iota(par.begin(), par.end(), 0);
        no_comp = n;
    }
    int leader(int x) {
        if (par[x] == x)
            return x;
        else
            return (par[x] = leader(par[x]));
    }
    bool is_connected(int x, int y) {
        return (leader(x) == leader(y));
    }
    int size(int x) {
        return sizz[leader(x)];
    }
    bool merge(int x, int y) {
        int x_ = leader(x);
        int y_ = leader(y);
        if (x_ == y_)
            return false;
        no_comp--;
        if (size(x_) < size(y_))
            swap(x_, y_);
        sizz[x_] += sizz[y_];
        max_csize = max(max_csize, sizz[x_]);
        par[y_] = leader(x_);
        return true;
    }
};

int Kruskal(int n, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap;
    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            min_heap.push(make_pair(it.second, make_pair(i, it.first)));
        }
    }
    DSK ds(n);
    int ans = 0;
    while (!min_heap.empty()) {
        pair < int, pair<int, int>> p = min_heap.top();
        min_heap.pop();
        if (ds.merge(p.second.first, p.second.second))
            ans += p.first;
        if (ds.no_comp == 1)
            break;
    }
    if (ds.no_comp != 1)
        return -1;
    else
        return ans;
}


/*
This is the template for Dijikstra's Algorithm

It returns shortest path(vector<int>) from 0 to n - 1 if exist or
empty vector if path don't exist

return the dist vector if you need the shortest distance
from the source node (as in parameters) to every other node.

dist is pinf if the respective node is unreachable from
the source node

important-->prepare adj list very carefully for directed graph
i.e
adj[a].emplace_back(make_pair(b, w));
adj[b].emplace_back(make_pair(a, w));(don't miss it)
*/

vector<int> Dijikstra(int node, int n, vector<vector<pair<int, int>>> &adj) {
    vector<int> vis(n), dist(n, pinf);
    vector<int> par(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> m;
    m.push({0, node});
    dist[node] = 0;
    while (!m.empty()) {
        pair<int, int> t = m.top();
        m.pop();
        int curNode = t.second;
        int d = t.first;
        if (vis[curNode])
            continue;
        vis[curNode] = 1;
        for (auto it : adj[curNode]) {
            if (d + it.second < dist[it.first]) {
                par[it.first] = curNode;
                dist[it.first] = d + it.second;
                m.push({dist[it.first], it.first});
            }
        }
    }
    if (dist[n - 1] == pinf)
        return {};
    vector<int> sp;
    int node_ = n - 1;
    while (true) {
        sp.eb(node_);
        if (node_ == 0)
            break;
        node_ = par[node_];
    }
    reverse(sp.begin(), sp.end());
    return sp;
}

vector<int> BellmanFord(int n, vector<int> &dist, vector<vector<pair<int, int>>> &adj) {
    dist[0] = 0;
    vector<int> par(n);
    par[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int a = 0; a < n; a++) {
            for (auto it : adj[a]) {
                int b = it.first;
                int w = it.second;
                if (dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                    par[b] = a;
                }
            }
        }
    }
    bool chk_ = false;
    int node;
    for (int a = 0; a < n; a++) {
        for (auto it : adj[a]) {
            int b = it.first;
            int w = it.second;
            if (dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                par[b] = a;
                node = b;
                chk_ = true;
                break;
            }
        }
        if (chk_)
            break;
    }
    if (!chk_)
        return {};
    vector<int> ans;
    for (int i = 0; i < n + 5; i++)
        node = par[node];
    ans.emplace_back(node);
    int x_x = par[node];
    while (true) {
        if (x_x != node)
            ans.emplace_back(x_x);
        else
            break;
        x_x = par[x_x];
    }
    ans.emplace_back(node);
    reverse(ans.begin(), ans.end());
    return ans;
}



vector<int> topoSort(int n, vector<vector<int>> &adj)
{

    vector<int> vis(n), indegree(n);
    for (int i = 0; i < n; i++) {
        for (auto x : adj[i]) {
            indegree[x]++;
        }
    }

    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            ans.emplace_back(i);
        }
    }

    while (!q.empty()) {
        int o_o = q.front();
        q.pop();
        for (auto it : adj[o_o]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
                ans.emplace_back(it);
            }
        }
    }

    return ans;

}

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

// vi f;
// int alpha =;
// for ( int i = 1; i * i <= alpha; i++) {
//     if (alpha % i == 0)
//     {
//         f.eb(i);
//         if (i != alpha / i)
//             f.eb(alpha / i);
//     }
// }
// make_unique(f);

// auto help = [&](pii from, pii to)->char {
//     if (from.F + 1 == to.F && from.S == to.S)
//         return 'D';
//     if (from.F - 1 == to.F && from.S == to.S)
//         return 'U';
//     if (from.F == to.F && from.S + 1 == to.S)
//         return 'R';
//     if (from.F == to.F && from.S - 1 == to.S)
//         return 'L';
// };
