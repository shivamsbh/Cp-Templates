typedef long long ll;

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
  mi& operator/=(const mi& m) { return (*this) *= inverse(m); }
  friend mi pow(mi a, ll p) {
    mi ans = 1; assert(p >= 0);
    for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
    return ans;
  }
  friend mi inverse(const mi& a) {
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

mi fac[10001];
mi ifac[10001];

void pre() {
  fac[0] = 1;
  ifac[0] = inverse(fac[0]);
  for (ll i = 1; i <= 10000; i++) {
    fac[i] = (fac[i - 1] * i);
    ifac[i] = inverse(fac[i]);
  }
}

mi ncr(ll n, ll r) {
  if (n < 0 || r < 0)
    return (mi)0;
  if (r == 0)
    return (mi)1;
  if (r > n) return (mi)0;
  return fac[n] * (ifac[r]) * ifac[n - r];
}

#define vmi  vector<mi>
#define vvmi vector<vmi>
#define vvvmi vector<vvmi>
