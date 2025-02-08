struct FenwickTree {
    vector<int> bit;  // 1-based indexing
    int n;

    // Initialize from vector (0-based input)
    FenwickTree(const vector<int>& nums) : n(nums.size()) {
        bit.resize(n + 1, 0);  // BIT is 1-based
        for (int i = 0; i < n; i++) {
            point_update(i + 1, nums[i]);  // Convert to 1-based index
        }
    }

    // Point update: Add delta to index (1-based)
    void point_update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    // Prefix sum [1..idx]
    int prefix_query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    // Range sum [l..r] (1-based boundaries)
    int range_query(int l, int r) {
        return prefix_query(r) - prefix_query(l - 1);
    }

    // Get original array value at position (1-based)
    int get(int idx) {
        return range_query(idx, idx);
    }

    // Set value at position (1-based)
    void set(int idx, int value) {
        int current = get(idx);
        point_update(idx, value - current);
    }
};
