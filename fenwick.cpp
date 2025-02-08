struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int size) : n(size + 1) {
        bit.resize(n, 0);
    }

    // Point update: Add delta to index (1-based)
    void update(int idx, int delta) {
        for (; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }

    // Prefix sum query [1..idx] (1-based)
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    // Range sum query [l..r] (1-based)
    int range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
