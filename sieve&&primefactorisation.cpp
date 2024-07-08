vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.emplace_back(i);
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

vector<int> primefactorisation(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.emplace_back(minp[x]);
        x = x / minp[x];
    }
    return ret;
}
