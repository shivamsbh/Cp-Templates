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
    for (int i = 1; i <= (int)2e6; i++)
        fact.eb(i * fact[i - 1]);
}

#define vmi  vector<mi>
#define vvmi vector<vmi>
#define vvvmi vector<vvmi>
