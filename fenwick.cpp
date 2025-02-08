struct FenwickTree {
    vector<int> bit;  // Internal 1-based storage
    int n;

    FenwickTree(const vector<int>& nums) : n(nums.size()) {
        bit.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            point_update(i + 1, nums[i]);  // Convert 0-based input to 1-based storage
        }
    }

    // Internal method remains 1-based
    void point_update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    // Internal method remains 1-based
    int prefix_query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    // Public interface uses 0-based indices
    int range_query(int l, int r) {
        return prefix_query(r + 1) - prefix_query(l);
    }

    int get(int idx) {
        return prefix_query(idx + 1) - prefix_query(idx);
    }

    void set(int idx, int value) {
        int current = get(idx);
        point_update(idx + 1, value - current);  // Convert to 1-based index
    }
};
